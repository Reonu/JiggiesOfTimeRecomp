#include "modding.h"
#include "structs.h"
#include "enums.h"
#include "recomputils.h"
#include "recompconfig.h"

RECOMP_IMPORT("*", void bkrecomp_notesaving_clear_all_map_note_counts(void));
RECOMP_IMPORT("*", void bkrecomp_notesaving_set_map_static_note_count(u32 map_id, u16 static_note_count));
RECOMP_IMPORT("*", void bkrecomp_notesaving_set_map_dynamic_note_count(u32 map_id, u16 dynamic_note_count));

RECOMP_CALLBACK("*", recomp_on_init) void on_init() {
    recomp_change_save_file("save");

    bkrecomp_notesaving_clear_all_map_note_counts();

    bkrecomp_notesaving_set_map_static_note_count(MAP_2_MM_MUMBOS_MOUNTAIN, 35);
    bkrecomp_notesaving_set_map_dynamic_note_count(MAP_2_MM_MUMBOS_MOUNTAIN, 5);
    bkrecomp_notesaving_set_map_static_note_count(MAP_5_TTC_BLUBBERS_SHIP, 38);
    bkrecomp_notesaving_set_map_static_note_count(MAP_7_TTC_TREASURE_TROVE_COVE, 70);
    bkrecomp_notesaving_set_map_static_note_count(MAP_B_CC_CLANKERS_CAVERN, 45);
    bkrecomp_notesaving_set_map_static_note_count(MAP_C_MM_TICKERS_TOWER, 10);
    bkrecomp_notesaving_set_map_static_note_count(MAP_D_BGS_BUBBLEGLOOP_SWAMP, 25);
    bkrecomp_notesaving_set_map_static_note_count(MAP_10_BGS_MR_VILE, 5);
    bkrecomp_notesaving_set_map_static_note_count(MAP_12_GV_GOBIS_VALLEY, 60);
    bkrecomp_notesaving_set_map_static_note_count(MAP_15_GV_WATER_PYRAMID, 20);
    bkrecomp_notesaving_set_map_static_note_count(MAP_1B_MMM_MAD_MONSTER_MANSION, 50);
    bkrecomp_notesaving_set_map_static_note_count(MAP_1D_MMM_CELLAR, 5);
    bkrecomp_notesaving_set_map_static_note_count(MAP_23_CC_GOLDFEATHER_ROOM, 10);
    bkrecomp_notesaving_set_map_static_note_count(MAP_26_MMM_NAPPERS_ROOM, 5);
    bkrecomp_notesaving_set_map_static_note_count(MAP_27_FP_FREEZEEZY_PEAK, 30);
    bkrecomp_notesaving_set_map_static_note_count(MAP_29_MMM_NOTE_ROOM, 5);
    bkrecomp_notesaving_set_map_static_note_count(MAP_2A_MMM_FEATHER_ROOM, 20);
    bkrecomp_notesaving_set_map_static_note_count(MAP_2B_MMM_SECRET_CHURCH_ROOM, 5);
    bkrecomp_notesaving_set_map_static_note_count(MAP_2D_MMM_BEDROOM, 5);
    bkrecomp_notesaving_set_map_static_note_count(MAP_2E_MMM_HONEYCOMB_ROOM, 15);
    bkrecomp_notesaving_set_map_static_note_count(MAP_34_RBB_ENGINE_ROOM, 15);
    bkrecomp_notesaving_set_map_static_note_count(MAP_36_RBB_BOATHOUSE, 5);
    bkrecomp_notesaving_set_map_static_note_count(MAP_38_RBB_CONTAINER_3, 15);
    bkrecomp_notesaving_set_map_static_note_count(MAP_3C_RBB_KITCHEN, 15);
    bkrecomp_notesaving_set_map_static_note_count(MAP_3D_RBB_NAVIGATION_ROOM, 27);
    bkrecomp_notesaving_set_map_static_note_count(MAP_3F_RBB_CAPTAINS_CABIN, 5);
    bkrecomp_notesaving_set_map_static_note_count(MAP_41_FP_BOGGYS_IGLOO, 5);
    bkrecomp_notesaving_set_map_static_note_count(MAP_43_CCW_SPRING, 25);
    bkrecomp_notesaving_set_map_static_note_count(MAP_44_CCW_SUMMER, 15);
    bkrecomp_notesaving_set_map_static_note_count(MAP_46_CCW_WINTER, 23);
    bkrecomp_notesaving_set_map_static_note_count(MAP_4C_CCW_AUTUMN_MUMBOS_SKULL, 4);
    bkrecomp_notesaving_set_map_static_note_count(MAP_53_FP_CHRISTMAS_TREE, 10);
    bkrecomp_notesaving_set_map_static_note_count(MAP_6A_GL_TTC_AND_CC_PUZZLE, 12);
    bkrecomp_notesaving_set_map_static_note_count(MAP_6B_GL_180_NOTE_DOOR, 40);
    bkrecomp_notesaving_set_map_dynamic_note_count(MAP_6B_GL_180_NOTE_DOOR, 15);
    bkrecomp_notesaving_set_map_static_note_count(MAP_6E_GL_GV_LOBBY, 20);
    bkrecomp_notesaving_set_map_static_note_count(MAP_6F_GL_FP_LOBBY, 5);
    bkrecomp_notesaving_set_map_static_note_count(MAP_71_GL_STATUE_ROOM, 45);
    bkrecomp_notesaving_set_map_static_note_count(MAP_72_GL_BGS_LOBBY, 30);
    bkrecomp_notesaving_set_map_static_note_count(MAP_77_GL_RBB_LOBBY, 30);
    bkrecomp_notesaving_set_map_static_note_count(MAP_78_GL_RBB_AND_MMM_PUZZLE, 25);
    bkrecomp_notesaving_set_map_static_note_count(MAP_79_GL_CCW_LOBBY, 30);
    bkrecomp_notesaving_set_map_static_note_count(MAP_7F_FP_WOZZAS_CAVE, 5);
    bkrecomp_notesaving_set_map_static_note_count(MAP_80_GL_FF_ENTRANCE, 35);
}
