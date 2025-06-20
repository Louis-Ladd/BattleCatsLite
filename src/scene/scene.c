#include "scene.h"
#include "../application.h"
#include "../log.h"
#include "../render/image.h"
#include <SDL2/SDL_keycode.h>

Scene* CreateScene()
{
    Scene* scene = malloc(sizeof(*scene));

    GenericUIElementList generic_list = CreateElementList(0);

    return scene;
}

void RenderScene(Scene* scene)
{
    RenderAssets(scene->scene_assets);
    for (int i = 0; i < scene->entity_count; i++)
    {
        if (!scene->entities[i])
        {
            continue;
        }
        Entity* current_entity = scene->entities[i];

        current_entity->behavior.render(current_entity);
        e_UpdateAnimation(current_entity);
    }

    RenderUIElementList(&scene->scene_ui);
}

void RenderAssets(SceneAsset assets[SCENE_ASSET_COUNT])
{
    for (int i = 0; i < SCENE_ASSET_COUNT; i++)
    {
        if (!assets[i].asset)
        {
            // Treat null as a terminator, we shouldn't have gaps in this arr.
            return;
        }
        switch (assets[i].type)
        {
            case BACKDROP:
                r_DrawImage(application.renderer, (Image*)(assets[i].asset));
                break;
            case SPRITESHEET:
                continue;
            default:
                LOG_WARN("Unknown AssetType, unable to render type: %i",
                         assets[i].type);
                continue;
        }
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

        LOG_DEBUG("Added entity with ID %i", i);

        return;
    }
    LOG_WARN("Unable to add entity as there's no more room!");
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
        LOG_DEBUG("Removed entity with id %i", entity->id);
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

        Entity* new_entity =
            e_CreateGenericGoodCat((Image*)scene->scene_assets[1].asset);

        AddEntity(scene, new_entity);
        ResetKey(SDLK_a);
    }

    if (application.keys[SDLK_d])
    {
        Entity* new_entity =
            e_CreateGenericBadCat((Image*)scene->scene_assets[1].asset);

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
