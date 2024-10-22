#ifndef SCENE_H_
#define SCENE_H_

#include "SDL2/SDL.h"
#include "../entity/entity.h"
#include "../render/sprite.h"
#include "../input/keyboard.h"
#include "../entity/entity_behavior.h"
#include "../cats/cat.h"

typedef struct {
    u16 entity_count;
    Entity** entities;
    Image* scene_images[3]; // Background, enemy spritesheet, friendly spritesheet
} Scene;

Scene* CreateScene();

void RenderScene(SDL_Renderer* renderer, Scene* scene);

void AddEntity(Scene* scene, Entity* entity);

void UpdateScene(Scene* scene);

void DestroyScene(Scene* scene);

#endif
