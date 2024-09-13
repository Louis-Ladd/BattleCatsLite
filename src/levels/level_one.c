#include "level.h"

void create_level_one(SDL_Renderer* renderer, SceneManager* scene_manager)
{
    Scene* scene = CreateScene();


    Image* friendly_sprite_sheet = r_CreateImage(renderer, IMG_Load("./assets/catspritesheet.png"), 0, 0, 2560, 2560);

    scene->entity_count = 64;
    scene->entities = malloc(sizeof(Entity) * 64);

    for (int i = 0; i < scene->entity_count; i++)
    {
        scene->entities[i] = NULL;
    }

    Sprite* sprite = r_CreateSprite(1, friendly_sprite_sheet, 50, 50, 1);
    Entity* entity = CreateEntity(0, sprite, 0, 100, false);

    scene->entities[0] = entity;

    AddScene(scene_manager, scene);
}
