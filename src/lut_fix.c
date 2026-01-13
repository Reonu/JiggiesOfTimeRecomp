#include "modding.h"
#include "recomputils.h"
#include "structs.h"

Gfx **modelRender_gfx;

RECOMP_HOOK("modelRender_draw") void before_modelRender_draw(Gfx **gfx, Mtx **mtx, f32 position[3], f32 rotation[3], f32 scale, f32*arg5, BKModelBin* model_bin) {
    modelRender_gfx = gfx;
}

RECOMP_HOOK_RETURN("modelRender_draw") void after_modelRender_draw() {
    // Reset the TLUT state after drawing models to prevent some bugged models from leaking it to the next one.
    if (modelRender_gfx) {
        gDPSetTextureLUT((*modelRender_gfx)++, G_TT_NONE);
    }
    modelRender_gfx = NULL;
}
