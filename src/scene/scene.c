#include "scene.h"
#include <time.h>

Scene* CreateScene()
{
    Scene* scene = malloc(sizeof(Scene));

    return scene;
}

void RenderScene(SDL_Renderer* renderer, Scene* scene)
{
    for (int i = 0; i < scene->entity_count; i++)
    {
        if (scene->entities[i] == NULL)
        { continue; }
        r_DrawSprite(renderer, scene->entities[i]->sprite);
    }
}

void UpdateScene(Scene* scene)
{
    Entity* entity = NULL;
    for (int i = 0; i < scene->entity_count; i++)
    {
        entity = scene->entities[i];
        if (!entity)
        { return; }

        if (entity->sprite->f_rect.y <= 480.0f - entity->sprite->f_rect.h * entity->sprite->scale)
        {
            if (entity->velocity.y < 0.8f)
            {
                entity->velocity.y += 0.1f;
            }
        }
        else
        {
            entity->velocity.y = 0;
        }

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
