#include "../application.h"
#include "level.h"
#include <SDL2/SDL_image.h>

void create_level_one(SceneManager* scene_manager)
{
    Scene* scene = CreateScene();

    SceneAsset scene_background = {
        BACKDROP, 
		(void*)(r_CreateImage(application.renderer,
                              IMG_Load("./assets/background.png"),
							  0, 0, 1280, 720))};

    SceneAsset scene_spritesheet = {
        SPRITESHEET,
        r_CreateImage(application.renderer,
                      IMG_Load("./assets/catspritesheet.png"),
					  0, 0, 2560, 2560)

    };

    scene->scene_assets[0] = scene_background;

    scene->scene_assets[1] = scene_spritesheet;

    scene->entity_count = 200;
    scene->entities = malloc(sizeof(Entity) * scene->entity_count);

    for (int i = 0; i < scene->entity_count; i++)
    {
        scene->entities[i] = NULL;
    }

    // Scenes have responsibility for all objects.
    // We shouldn't be creating entities without giving ownership
    // to a scene

    /*for (int i = 0; i < 20; i++)*/
    /*{*/
    /*    Entity* entity =
     * e_CreateGenericGoodCat(scene->scene_images[1]);*/
    /*    entity->position.x -= i * 5;*/
    /*    AddEntity(scene, entity);*/
    /**/
    /*    entity =
     * e_CreateGenericBadCat(scene->scene_images[1]);*/
    /*    entity->position.x += i * 5;*/
    /*    AddEntity(scene, entity);*/
    /*}*/

    Entity* entity = e_CreateGenericBadCat((Image*)scene->scene_assets[1].asset);
    AddEntity(scene, entity);

    AddScene(scene_manager, scene);
}
