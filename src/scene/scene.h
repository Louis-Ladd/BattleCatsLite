#ifndef SCENE_H_
#define SCENE_H_

#include "../cats/cat.h"
#include "../entity/entity.h"
#include "../entity/entity_behavior.h"
#include "../input/keyboard.h"
#include "../render/sprite.h"
#include "SDL2/SDL.h"

typedef struct {
    u16 entity_count;
    Entity** entities;
    Image* scene_images[3];
} Scene;

Scene* CreateScene();

void RenderScene(SDL_Renderer* renderer, Scene* scene);

void AddEntity(Scene* scene, Entity* entity);

void UpdateScene(Scene* scene);

void DestroyScene(Scene* scene);

#endif
