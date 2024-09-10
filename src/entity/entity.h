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
} Entity;

Entity* CreateEntity(EntityID id, Sprite* sprite, u8 current_frame, u16 health, bool is_enemy);

#endif