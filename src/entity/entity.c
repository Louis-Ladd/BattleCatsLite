#include "entity.h"

Entity* CreateEntity(EntityID id, Sprite* sprite, u8 current_frame, u16 health, bool is_enemy)
{
    Entity* entity = malloc(sizeof(entity));

    entity->id = id;
    entity->sprite = sprite;
    entity->current_frame = current_frame;
    entity->health = health;
    entity->is_enemy = is_enemy;

    return entity;
}

void DestroyEntity(Entity* entity)
{
    r_DestroySprite(entity->sprite);
    free(entity);
}