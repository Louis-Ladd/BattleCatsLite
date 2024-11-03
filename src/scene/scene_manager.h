#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#define SCENE_COUNT 2

#include "scene.h"

typedef struct
{
    Scene* scenes[SCENE_COUNT];
} SceneManager;

SceneManager* InitSceneManager();

void AddScene(SceneManager* scene_manager, Scene* scene);

void RemoveScene(SceneManager* scene_manager, Scene* scene);

void DestroySceneManager(SceneManager* scene_manager);

#endif
