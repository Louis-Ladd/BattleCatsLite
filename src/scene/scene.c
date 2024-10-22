#include "scene.h"
#include <SDL2/SDL_keycode.h>

Scene* CreateScene()
{
    Scene* scene = malloc(sizeof(*scene));

    return scene;
}

void RenderScene(SDL_Renderer* renderer, Scene* scene)
{
    for (int i = 0; i < scene->entity_count; i++)
    {
        if (!scene->entities[i])
        { continue; }

        r_RenderEntity(renderer, scene->entities[i]);
    }
}

void AddEntity(Scene* scene, Entity* entity)
{
    for (int i = 0; i < scene->entity_count; i++)
    {
        if (scene->entities[i] != NULL)
        { continue; }

        scene->entities[i] = entity;
        scene->entities[i]->id = i;
        return;
    }
    // TODO: Do something if we were unable to add the entity
}

void UpdateScene(Scene* scene)
{
    Entity* entity = NULL;
    for (int i = 0; i < scene->entity_count; i++)
    {
        entity = scene->entities[i];
        if (!entity)
        { return; }

        for (int j = 0; j < scene->entity_count; j++)
        {
            if (!scene->entities[j])
            { continue; }
            if (entity == scene->entities[j])
            { continue;}

            if (entity->is_enemy)
            {
                e_UpdateBadCat(entity, scene->entities[j]);
            }
            else
            {
                e_UpdateGoodCat(entity, scene->entities[j]);
            }
        }

        e_EntityGravity(entity);
        e_ApplyEntropy(entity);
        e_ApplyVelocity(entity);
    }
}

void DestroyScene(Scene* scene)
{
    for (int i = 0; i < scene->entity_count; i++)
    {
        e_DestroyEntity(scene->entities[i]);
    }
}
