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

    // Scenes have responsibility for all objects.
    // We shouldn't be creating entities without giving ownership to a scene

    for (int i = 0; i < 100; i++) {
        Entity* entity = e_CreateGenericGoodCat(friendly_sprite_sheet);
        AddEntity(scene, entity);

        entity = e_CreateGenericBadCat(friendly_sprite_sheet);
        AddEntity(scene, entity);
    }

    AddScene(scene_manager, scene);
}
