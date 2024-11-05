#include "entity.h"
#include "../application.h"
#include "../log.h"

Entity* e_CreateEntity(EntityID id, Sprite* sprite, u8 current_frame,
                       u16 health, bool is_enemy,
                       void (*update_func)(Entity* self, Entity* other),
                       void (*render_func)(Entity* self))
{

    Entity* entity = malloc(sizeof(*entity));

    entity->id = id;
    entity->sprite = sprite;
    entity->current_frame = current_frame;
    entity->health = health;
    entity->is_enemy = is_enemy;
    entity->position.x = sprite->f_rect.x;
    entity->position.y = sprite->f_rect.y;
    entity->velocity.x = 0;
    entity->velocity.y = 0;
    entity->behavior.update = update_func;
    entity->behavior.render = render_func;

    return entity;
}

void r_RenderEntity(Entity* entity)
{
    if (!entity)
    {
        return;
    }

    entity->sprite->f_rect.x =
        entity->position.x -
        (entity->sprite->f_rect.w * entity->sprite->scale) / 2;
    entity->sprite->f_rect.y =
        entity->position.y - (entity->sprite->f_rect.h * entity->sprite->scale);
    // TODO: Add animation support

    r_DrawSprite(application.renderer, entity->sprite);
}

void e_UpdateAnimation(Entity* entity)
{
    u32 time_since_last_update =
        SDL_GetTicks() - entity->sprite->last_animation_update;

    if (time_since_last_update <= 250)
    {
        return;
    }

    entity->sprite->last_animation_update = SDL_GetTicks();

    if (entity->sprite->animation_frame < 9)
    {
        entity->sprite->animation_frame++;
    }
    else
    {
        entity->sprite->animation_frame = 0;
    }
}

inline void e_ApplyVelocity(Entity* entity)
{
    entity->position.x += entity->velocity.x * application.delta_time;
    entity->position.y += entity->velocity.y * application.delta_time;
}

void e_DestroyEntity(Entity* entity)
{
    r_DestroySprite(entity->sprite);
    free(entity);
}
