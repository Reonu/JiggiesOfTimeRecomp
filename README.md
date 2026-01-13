# Jiggies of Time Recomp

This is the new code written for the recomp version of Jiggies of Time. This repo expects mod_syms.bin and mod_binary.bin from the romhack tool to be placed in the root folder before building.

### Build steps

1. Follow the instructions to install build tools found [here](https://github.com/BanjoRecomp/BKRecompModTemplate).
2. Build the `RecompModTool` and `RecompModMerger` utilties from the [N64Recomp repo](https://github.com/N64Recomp/N64Recomp) and place them in the root folder of this project.
3. Run the BKRecompRomhackTool using the `jiggiesoftime_syms.toml` file in this repo to generate the `mod_syms.bin` and `mod_binary.bin` files. Place those in the root folder of this project.
4. Place the Jiggies of Time bps file (sha1sum 52b5f50d4d12a3a7fed081b1afc38ddfbbed12e0) in the root of this repo and name it "patch.bps". 
5. Run `make`.
