#include "modding.h"
#include "recomputils.h"
#include "structs.h"
#include "prop.h"
#include "functions.h"

RECOMP_IMPORT("*", s32 bkrecomp_note_saving_active(void));

#define ACTOR_NOTE_SIGN 0x0054
#define MODEL_NOTE_SIGN 0x03EB

extern s32 sSpawnableActorSize;
extern ActorSpawn *sSpawnableActorList;

void (*noteSignUpdate)(Actor*) = NULL;

void noteSignUpdateWrapper(Actor *actor) {
    // Call the original update function.
    if (noteSignUpdate) {
        noteSignUpdate(actor);
    }

    // Despawn the sign if note saving is active and this actor has the note sign's model ID.
    if (actor->actor_info->modelId == MODEL_NOTE_SIGN && bkrecomp_note_saving_active()) {
        marker_despawn(actor->marker);
    }
}

void (*tutorialBottlesUpdate)(Actor*) = NULL;

void tutorialBottlesUpdateWrapper(Actor *actor) {
    // Despawn the tutorial bottles mound that explains note signs if note saving is active.
    if (actor->actorTypeSpecificField == 0x08 && bkrecomp_note_saving_active()) {
        // Despawn the molehill if it exists.
        if (actor->partnerActor) {
            marker_despawn(actor->partnerActor);
        }
        marker_despawn(actor->marker);
        return;
    }

    if (tutorialBottlesUpdate) {
        tutorialBottlesUpdate(actor);
    }
}

RECOMP_HOOK("spawnableActorList_add") void on_spawnable_actor_list_add(ActorInfo *arg0, Actor *(*arg1)(s32[3], s32, ActorInfo *, u32), u32 arg2) {
    // Replace the update function for the note sign with a wrapper that calls the original update function.
    if (arg0->actorId == ACTOR_NOTE_SIGN) {
        if (arg0->update_func != noteSignUpdateWrapper) {
            noteSignUpdate = arg0->update_func;
            arg0->update_func = noteSignUpdateWrapper;
        }
    }
    if (arg0->actorId == ACTOR_12B_TUTORIAL_BOTTLES) {
        if (arg0->update_func != tutorialBottlesUpdateWrapper) {
            tutorialBottlesUpdate = arg0->update_func;
            arg0->update_func = tutorialBottlesUpdateWrapper;
        }
    }
}
