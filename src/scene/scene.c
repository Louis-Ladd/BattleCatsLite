#include "scene.h"

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