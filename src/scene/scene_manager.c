#include "scene_manager.h"
#include "scene.h"

SceneManager* InitSceneManager()
{
    SceneManager* scene_manager = malloc(sizeof(SceneManager));
    for (int i = 0; i < SCENE_COUNT; i++)
    {
        scene_manager->scenes[i] = NULL;
    }

    return scene_manager;
}

void AddScene(SceneManager* scene_manager, Scene* scene)
{
    for (int i = 0; i < SCENE_COUNT; i++)
    {
        if (scene_manager->scenes[i])
        {
            if (i == SCENE_COUNT - 1)
            {
                printf("Warning: Attempted to add a scene but we don't have "
                       "room!");
                return;
            }
            continue;
        }

        scene_manager->scenes[i] = scene;
        return;
    }
}

// We have responsiblity for cleanup!!!!
void RemoveScene(SceneManager* scene_manager, Scene* scene)
{
    for (int i = 0; i < SCENE_COUNT; i++)
    {
        if (scene == scene_manager->scenes[i])
        {
            DestroyScene(scene);
            scene_manager->scenes[i] = NULL;
        }
    }
}

void DestroySceneManager(SceneManager* scene_manager)
{
    // TODO: Go through all scenes and clean them up properly!!!
    free(scene_manager);
}
