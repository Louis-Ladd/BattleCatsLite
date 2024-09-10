#ifndef SCENE_H_
#define SCENE_H_

#include "../entity/entity.h"
#include "../render/sprite.h"
#include "SDL2/SDL.h"

typedef struct {
    u16 entity_count;
    Entity** entities;
    Image* scene_images[3]; // Background, enemy spritesheet, friendly spritesheet
} Scene;

Scene* CreateScene();

void RenderScene(SDL_Renderer* renderer, Scene* scene);

#endif