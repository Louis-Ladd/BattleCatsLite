#ifndef SCENE_H_
#define SCENE_H_

#include "../entity/entity.h"
#include "SDL2/SDL.h"

typedef struct {
    Entity* entities;
    u16 entity_count;
} Scene;

void RenderScene(SDL_Renderer* renderer);

#endif