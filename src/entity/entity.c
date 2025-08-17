#include "entity.h"
#include "../application.h"
#include "../log.h"
#include <SDL2/SDL_log.h>

Entity* e_CreateEntity(EntityID id, Sprite* sprite, u16 health, bool is_enemy,
                       void (*update_func)(Entity* self, Entity* other),
                       void (*render_func)(Entity* self))
{
    Entity* entity = malloc(sizeof(*entity));

    entity->id = id;
    entity->sprite = sprite;
    entity->current_state = WALKING;
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

    r_DrawSprite(application.renderer, entity->sprite);
}

void e_UpdateAnimation(Entity* entity)
{
    u32 time_since_last_update =
        SDL_GetTicks() - entity->sprite->last_animation_update;

    switch (entity->current_state)
    {
        case WALKING:
            if (entity->sprite->animation_frame >= 3)
            {
                entity->sprite->animation_frame = 0;
                break;
            }
            if (time_since_last_update >= 150)
            {
                entity->sprite->animation_frame++;
                entity->sprite->last_animation_update = SDL_GetTicks();
            }
            break;
        case ATTACKING:
            if (entity->sprite->animation_frame > 6)
            {
                e_SetEntityState(entity, WALKING);
                break;
            }
            if (time_since_last_update >= 150)
            {
                entity->sprite->animation_frame++;
                entity->sprite->last_animation_update = SDL_GetTicks();
            }
            break;
        case HURT:
            if (entity->sprite->animation_frame > 9)
            {
                e_SetEntityState(entity, WALKING);
                break;
            }
            if (time_since_last_update >= 350)
            {
                entity->sprite->animation_frame++;
                entity->sprite->last_animation_update = SDL_GetTicks();
            }
            break;
        default:
            LOG_ERROR("The unthinkable has happened and the perfect case "
                      "statement I've written has fallen through.");
            break;
    }
}

void e_SetEntityState(Entity* entity, enum EntityState state)
{
    switch (state)
    {
        case WALKING:
            entity->sprite->animation_frame = 0;
            entity->current_state = state;
            break;
        case ATTACKING:
            entity->sprite->animation_frame = 4;
            entity->current_state = state;
            break;
        case HURT:
            entity->sprite->animation_frame = 7;
            entity->current_state = state;
            break;
        default:
            LOG_WARN("Unknown state set for entity");
            break;
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

bool e_IsVisible(Entity* entity)
{
    if (entity->position.x < (0 - entity->sprite->f_rect.w))
        return false;
    if (entity->position.x > (GetScreenWidth() + entity->sprite->f_rect.w))
        return false;
    if (entity->position.y < (0 - entity->sprite->f_rect.h))
        return false;
    if (entity->position.y > (GetScreenHeight() + entity->sprite->f_rect.h))
        return false;

    return true;
}
