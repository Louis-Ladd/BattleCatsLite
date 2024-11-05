#include "../application.h"
#include "level.h"
#include <SDL2/SDL_image.h>

void create_level_one(SceneManager* scene_manager)
{
    Scene* scene = CreateScene();

    Image* scene_background =
        r_CreateImage(application.renderer, IMG_Load("./assets/background.png"),
                      0, 0, 1280, 720);

    scene->scene_images[0] = scene_background;

    scene->scene_images[1] = r_CreateImage(
        application.renderer, IMG_Load("./assets/catspritesheet.png"), 0, 0,
        2560, 2560);

    scene->entity_count = 200;
    scene->entities = malloc(sizeof(Entity) * scene->entity_count);

    for (int i = 0; i < scene->entity_count; i++)
    {
        scene->entities[i] = NULL;
    }

    // Scenes have responsibility for all objects.
    // We shouldn't be creating entities without giving ownership to a scene

    /*for (int i = 0; i < 20; i++)*/
    /*{*/
    /*    Entity* entity = e_CreateGenericGoodCat(scene->scene_images[1]);*/
    /*    entity->position.x -= i * 5;*/
    /*    AddEntity(scene, entity);*/
    /**/
    /*    entity = e_CreateGenericBadCat(scene->scene_images[1]);*/
    /*    entity->position.x += i * 5;*/
    /*    AddEntity(scene, entity);*/
    /*}*/

    Entity* entity = e_CreateGenericBadCat(scene->scene_images[1]);
    AddEntity(scene, entity);

    AddScene(scene_manager, scene);
}
