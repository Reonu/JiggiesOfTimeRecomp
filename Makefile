BUILD_DIR := build

# Allow the user to specify the compiler and linker on macOS
# as Apple Clang does not support MIPS architecture
ifeq ($(OS),Windows_NT)
    CC      := clang
    LD      := ld.lld
    PROG_SUFFIX := .exe
else ifneq ($(shell uname),Darwin)
    CC      := clang
    LD      := ld.lld
    PROG_SUFFIX := 
else
    CC      ?= clang
    LD      ?= ld.lld
    PROG_SUFFIX := 
endif

ZIP       := zip
MODTOOL   := RecompModTool
MODMERGER := RecompModMerger

ifeq ($(wildcard $(MODTOOL)$(PROG_SUFFIX)),)
$(error "Please place the RecompModTool executable in the root of this repo.")
endif

ifeq ($(wildcard $(MODMERGER)$(PROG_SUFFIX)),)
$(error "Please place the RecompModMerger executable in the root of this repo.")
endif

ifeq ($(wildcard mod_syms.bin),)
$(error "Please place the converted mod_syms.bin file from the romhack tool in the root of this repo.")
endif

ifeq ($(wildcard mod_binary.bin),)
$(error "Please place the converted mod_binary.bin file from the romhack tool in the root of this repo.")
endif

TARGET     := $(BUILD_DIR)/mod.elf
PRELIM_NRM := $(BUILD_DIR)/jiggiesoftime_prelim.nrm
NRM        := $(BUILD_DIR)/jiggiesoftime.nrm
NRM_ZIP    := $(BUILD_DIR)/jiggiesoftime.zip

LDSCRIPT := mod.ld
ARCHFLAGS := -target mips -mips2 -mabi=32 -O2 -G0 -mno-abicalls -mno-odd-spreg -mno-check-zero-division \
             -fomit-frame-pointer -ffast-math -fno-unsafe-math-optimizations -fno-builtin-memset -funsigned-char -fno-builtin-sinf -fno-builtin-cosf
WARNFLAGS := -Wall -Wextra -Wno-incompatible-library-redeclaration -Wno-unused-parameter -Wno-unknown-pragmas -Wno-unused-variable \
             -Wno-missing-braces -Wno-unsupported-floating-point-opt -Wno-cast-function-type-mismatch -Werror=section -Wno-visibility
CFLAGS   := $(ARCHFLAGS) $(WARNFLAGS) -D_LANGUAGE_C -nostdinc -ffunction-sections
CPPFLAGS := -nostdinc -DMIPS -DF3DEX_GBI -I include -I include/dummy_headers \
			-I bk-decomp/include -I bk-decomp/include/2.0L -I bk-decomp/include/2.0L/PR
LDFLAGS  := -nostdlib -T $(LDSCRIPT) -Map $(BUILD_DIR)/mod.map --unresolved-symbols=ignore-all --emit-relocs -e 0 --no-nmagic -gc-sections

rwildcard = $(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))
getdirs = $(sort $(dir $(1)))

C_SRCS := $(call rwildcard,src,*.c)
C_OBJS := $(addprefix $(BUILD_DIR)/, $(C_SRCS:.c=.o))
C_DEPS := $(addprefix $(BUILD_DIR)/, $(C_SRCS:.c=.d))

COMBINED_DIR := $(BUILD_DIR)/combined
COMBINED_BIN  := $(COMBINED_DIR)/mod_binary.bin
COMBINED_SYMS := $(COMBINED_DIR)/mod_syms.bin

ALL_OBJS := $(C_OBJS)
ALL_DEPS := $(C_DEPS)
BUILD_DIRS := $(call getdirs,$(ALL_OBJS)) $(COMBINED_DIR)

NRM_INPUTS := $(BUILD_DIR)/combined/mod_binary.bin $(BUILD_DIR)/combined/mod_syms.bin $(BUILD_DIR)/mod.json patch.bps thumb.dds
NRM_FILES  := $(NRM_INPUTS)

ifeq ($(OS),Windows_NT)
space := $(subst ,, )
comma:= ,
NRM_FILES  := $(subst $(space),$(comma),$(subst /,\,$(NRM_FILES)))
endif

all: $(NRM)

$(NRM): $(NRM_ZIP)
ifeq ($(OS),Windows_NT)
	copy /Y $(subst /,\,$<) $(subst /,\,$@)
else
	cp $< $@
endif

$(NRM_ZIP): $(COMBINED_SYMS)
	powershell -command Compress-Archive -Force -CompressionLevel Optimal -DestinationPath $@ -Path $(NRM_FILES)

$(COMBINED_SYMS): $(PRELIM_NRM)
	$(MODMERGER) BanjoRecompSyms/bk.us.rev0.syms.toml $(BUILD_DIR)/mod_syms.bin $(BUILD_DIR)/mod_binary.bin mod_syms.bin mod_binary.bin $(COMBINED_SYMS) $(COMBINED_BIN)

$(PRELIM_NRM): $(TARGET)
	$(MODTOOL) mod.toml $(BUILD_DIR)

$(TARGET): $(ALL_OBJS) $(LDSCRIPT) | $(BUILD_DIR)
	$(LD) $(ALL_OBJS) $(LDFLAGS) -o $@

$(BUILD_DIR) $(BUILD_DIRS):
ifeq ($(OS),Windows_NT)
	if not exist "$(subst /,\,$@)" mkdir "$(subst /,\,$@)"
else
	mkdir -p $@
endif

$(C_OBJS): $(BUILD_DIR)/%.o : %.c | $(BUILD_DIRS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -MMD -MF $(@:.o=.d) -c -o $@

clean:
ifeq ($(OS),Windows_NT)
	if exist $(BUILD_DIR) rmdir /S /Q $(BUILD_DIR)
else
	rm -rf $(BUILD_DIR)
endif

-include $(ALL_DEPS)

.PHONY: clean all

# Print target for debugging
print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true
