#ifndef ENTITY_H_
#define ENTITY_H_

#include "../render/sprite.h"
#include "../utils/util.h"
#include "stdbool.h"

typedef u16 EntityID;

typedef struct Entity Entity;

typedef struct {
    void (*update)(Entity* self, Entity* other);
    void (*render)(Entity* self);
} EntityBehavior;

struct Entity {
    EntityID id;
    Sprite* sprite;
    u8 current_frame;
    u16 speed;
    s16 health;
    bool is_enemy;
    Vec2 position;
    Vec2 velocity;
    EntityBehavior behavior;
};

Entity* e_CreateEntity(EntityID id, Sprite* sprite, u8 current_frame,
                       u16 health, bool is_enemy,
                       void (*update_func)(Entity* self, Entity* other),
                       void (*render_func)(Entity* self));

// Generic Render for any entity
void r_RenderEntity(Entity* entity);

void e_ApplyVelocity(Entity* entity);

void e_DestroyEntity(Entity* entity);

#endif
