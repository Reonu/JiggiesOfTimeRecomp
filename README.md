# Jiggies of Time Recomp

This repository contains the new code written for the Banjo: Recompiled version of the Banjo-Kazooie mod **BK The Jiggies of Time** by Kurko Mods.

### Build steps

1. Follow the instructions to install build tools found [here](https://github.com/BanjoRecomp/BKRecompModTemplate).
2. Build the `RecompModTool` and `RecompModMerger` utilties from the [N64Recomp repo](https://github.com/N64Recomp/N64Recomp) and place them in the root folder of this project.
3. Copy the `BKRecompRomhackTool` utility from [this repo](https://github.com/Mr-Wiseguy/BKRecompRomhackTool) into this folder.
4. Place a vanilla Banjo-Kazooie NTSC-U 1.0 ROM in the root of this repo and name it "baserom.z64". THe file's SHA1 checksum should be 1fe1632098865f639e22c11b9a81ee8f29c75d7a.
5. Place the Jiggies of Time bps file in the root of this repo and name it "patch.bps". The bps file's SHA1 checksum should be 9b345cf04320f5d3b3ec26c5fe372988d7bc2e1c.
6. Patch the Jiggies of Time bps file onto the Banjo-Kazooie NTSC-U 1.0 ROM and place the resulting ROM in the root of this repo with the name "bk_jiggies_of_time.z64". The resulting ROM's SHA1 checksum should be 674deb63b85fe87cd0b7500138012425e018646f.
7. Run `make`.
