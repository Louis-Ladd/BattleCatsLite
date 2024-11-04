#include "scene.h"
#include "../application.h"
#include "../log.h"
#include <SDL2/SDL_keycode.h>
#include <string.h>

Scene* CreateScene()
{
    Scene* scene = malloc(sizeof(*scene));

    return scene;
}

void RenderScene(Scene* scene)
{
    if (scene->scene_images[0])
    {
        r_DrawImage(application.renderer, scene->scene_images[0]);
    }

    for (int i = 0; i < scene->entity_count; i++)
    {
        if (!scene->entities[i])
        {
            continue;
        }
        Entity* current_entity = scene->entities[i];

        current_entity->behavior.render(current_entity);
    }
}

void AddEntity(Scene* scene, Entity* entity)
{
    for (int i = 0; i < scene->entity_count; i++)
    {
        if (scene->entities[i] != NULL)
        {
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

void RemoveEntity(Scene* scene, Entity* entity)
{
    for (int i = 0; i < scene->entity_count; i++)
    {
        if (!scene->entities[i])
        {
            continue;
        }
        if (scene->entities[i] != entity)
        {
            continue;
        }
        LOG("Removed entity with id %i", entity->id);
        e_DestroyEntity(entity);

        scene->entities[i] = NULL;
        return;
    }
}

void UpdateScene(Scene* scene)
{
    for (int i = 0; i < scene->entity_count; i++)
    {
        Entity* entity = scene->entities[i];
        if (entity == NULL)
        {
            continue;
        }

        for (int j = 0; j < scene->entity_count; j++)
        {
            Entity* other_entity = scene->entities[j];
            if (other_entity == NULL)
            {
                continue;
            }
            entity->behavior.update(entity, scene->entities[j]);
        }

        e_EntityGravity(entity);
        e_ApplyEntropy(entity);
        e_ApplyVelocity(entity);
    }

    if (application.keys[SDLK_a])
    {

        Entity* new_entity = e_CreateGenericGoodCat(scene->scene_images[1]);

        AddEntity(scene, new_entity);
        ResetKey(SDLK_a);
    }

    if (application.keys[SDLK_d])
    {
        Entity* new_entity = e_CreateGenericBadCat(scene->scene_images[1]);

        AddEntity(scene, new_entity);
        ResetKey(SDLK_d);
    }
}

void DestroyScene(Scene* scene)
{
    for (int i = 0; i < scene->entity_count; i++)
    {
        e_DestroyEntity(scene->entities[i]);
    }
}
