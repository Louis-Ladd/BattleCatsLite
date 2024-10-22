#ifndef ENTITY_H_
#define ENTITY_H_

#include "../utils/util.h"
#include "../render/sprite.h"
#include "stdbool.h"

typedef u16 EntityID;

typedef struct {
    EntityID id;
    Sprite* sprite;
    u8 current_frame;
    u16 speed;
    u16 health;
    bool is_enemy;
    Vec2 position;
    Vec2 velocity;
} Entity;

Entity* e_CreateEntity(EntityID id, Sprite* sprite, u8 current_frame, u16 health, bool is_enemy);

void r_RenderEntity(SDL_Renderer* renderer, Entity* entity);

void e_ApplyVelocity(Entity* entity);

void e_DestroyEntity(Entity* entity);

#endif
