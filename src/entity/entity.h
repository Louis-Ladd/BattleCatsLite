#ifndef ENTITY_H_
#define ENTITY_H_

#include "../utils/util.h"
#include "../render/sprite.h"
#include "stdbool.h"

typedef u16 EntityID;

typedef struct {
    EntityID id;
    Sprite* sprite; // Stores positional data
    u8 current_frame;
    u16 health;
    bool is_enemy;
    Vec2 velocity;
} Entity;

Entity* e_CreateEntity(EntityID id, Sprite* sprite, u8 current_frame, u16 health, bool is_enemy);

void e_ApplyVelocity(Entity* entity);

void e_DestroyEntity(Entity* entity);

#endif
