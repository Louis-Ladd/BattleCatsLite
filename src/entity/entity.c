#include "entity.h"

Entity* e_CreateEntity(EntityID id, Sprite* sprite, u8 current_frame, u16 health, bool is_enemy)
{
    Entity* entity = malloc(sizeof(*entity));

    entity->id = id;
    entity->sprite = sprite;
    entity->current_frame = current_frame;
    entity->health = health;
    entity->is_enemy = is_enemy;
    entity->velocity.x = 0;
    entity->velocity.y = 0;

    return entity;
}

void e_ApplyVelocity(Entity* entity)
{
    entity->sprite->f_rect.x += entity->velocity.x;
    entity->sprite->f_rect.y += entity->velocity.y;
}

void e_DestroyEntity(Entity* entity)
{
    r_DestroySprite(entity->sprite);
    free(entity);
}
