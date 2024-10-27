#include "scene.h"
#include "../log.h"
#include <SDL2/SDL_keycode.h>

Scene* CreateScene() {
    Scene* scene = malloc(sizeof(*scene));

    return scene;
}

void RenderScene(SDL_Renderer* renderer, Scene* scene) {
    for (int i = 0; i < scene->entity_count; i++) {
        if (!scene->entities[i]) {
            continue;
        }

        r_RenderEntity(renderer, scene->entities[i]);
    }
}

void AddEntity(Scene* scene, Entity* entity) {
    for (int i = 0; i < scene->entity_count; i++) {
        if (scene->entities[i] != NULL) {
            continue;
        }

        scene->entities[i] = entity;
        scene->entities[i]->id = i;

        LOG("Added entity with ID %i", i);

        return;
    }
    LOG("Unable to add entity as there's no more room!");
    e_DestroyEntity(entity);
    return;
}

void UpdateScene(Scene* scene) {
    Entity* entity = NULL;
    for (int i = 0; i < scene->entity_count; i++) {
        entity = scene->entities[i];
        if (!entity) {
            return;
        }

        for (int j = 0; j < scene->entity_count; j++) {
            if (!scene->entities[j]) {
                continue;
            }

            entity->behavior.update(entity, scene->entities[j]);
        }

        e_EntityGravity(entity);
        e_ApplyEntropy(entity);
        e_ApplyVelocity(entity);
    }
}

void DestroyScene(Scene* scene) {
    for (int i = 0; i < scene->entity_count; i++) {
        e_DestroyEntity(scene->entities[i]);
    }
}
