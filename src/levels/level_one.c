#include "../application.h"
#include "level.h"

void create_level_one(SceneManager* scene_manager) {
    Scene* scene = CreateScene();

    Image* friendly_sprite_sheet = r_CreateImage(
        application.renderer, IMG_Load("./assets/catspritesheet.png"), 0, 0,
        2560, 2560);

    scene->entity_count = 64;
    scene->entities = malloc(sizeof(Entity) * scene->entity_count);

    for (int i = 0; i < scene->entity_count; i++) {
        scene->entities[i] = NULL;
    }

    Entity* entity = e_CreateGenericGoodCat(0, friendly_sprite_sheet);
    scene->entities[0] = entity;

    entity = e_CreateGenericBadCat(1, friendly_sprite_sheet);
    scene->entities[1] = entity;

    AddScene(scene_manager, scene);
}
