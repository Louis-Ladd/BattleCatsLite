#include "cat.h"
#include "../application.h"
#include "../color.h"
#include "../entity/entity_behavior.h"
#include "../log.h"
#include <SDL2/SDL_assert.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

Entity* e_CreateGenericGoodCat(Image* sprite_sheet)
{
    Sprite* sprite = r_CreateSprite(0, sprite_sheet, 1400.0f, GROUND_Y, 0.5f);
    Entity* cat =
        e_CreateEntity(0, sprite, 100, false, e_UpdateGoodCat, r_RenderGoodCat);
    cat->speed = 100;
    cat->atk_dst = 150;

    return cat;
}

Entity* e_CreateGenericBadCat(Image* sprite_sheet)
{
    Sprite* sprite = r_CreateSprite(1, sprite_sheet, 0.0f, GROUND_Y, 0.5f);
    Entity* cat =
        e_CreateEntity(0, sprite, 100, true, e_UpdateBadCat, r_RenderBadCat);
    cat->speed = 100;
    cat->atk_dst = 150;

    return cat;
}

bool e_LifeUpdate(Entity* entity)
{
    if (entity->health <= 0 && entity)
    {
        RemoveEntity(application.scene_manager->scenes[0], entity);
        return true;
    }
    return false;
}

void e_UpdateGoodCat(Entity* self, Entity* other)
{
    if (e_LifeUpdate(self))
    {
        return;
    }

    if (fabs(self->velocity.x) < self->speed)
    {
        self->velocity.x -= 10.0f;
    }

    if (self == other)
    {
        return;
    }

    if (DistanceVec2(self->position, other->position) < self->atk_dst &&
        other->is_enemy)
    {
        e_SetEntityState(self, ATTACKING);
        e_GoodCatAttack(self, other);
    }

    return;
}

void e_UpdateBadCat(Entity* self, Entity* other)
{
    if (e_LifeUpdate(self))
    {
        return;
    }

    if (fabs(self->velocity.x) < self->speed)
    {
        self->velocity.x += 10.0f;
    }

    if (self == other)
    {
        return;
    }

    if (DistanceVec2(self->position, other->position) < self->atk_dst &&
        !other->is_enemy)
    {
        e_SetEntityState(self, ATTACKING);
        e_BadCatAttack(self, other);
    }

    return;
}

void r_DrawHealthBar(Entity* entity)
{
    if (!application.game_state.show_health_bar)
    {
        return;
    }

    SDL_Rect health_bar_background = {
        entity->position.x - 50,
        (entity->position.y -
         entity->sprite->f_rect.h * entity->sprite->scale) -
            50,
        100, 20};
    SDL_Rect health_bar_fill = health_bar_background;

    health_bar_fill.w = entity->health;

    SDL_SetRenderDraw_SDL_Color(application.renderer, BLACK);
    SDL_RenderFillRect(application.renderer, &health_bar_background);
    SDL_SetRenderDraw_SDL_Color(application.renderer, RED);
    SDL_RenderFillRect(application.renderer, &health_bar_fill);
    SDL_SetRenderDraw_SDL_Color(application.renderer, BLACK);
}

void r_DrawBoundingBox(Entity* entity)
{
    if (!application.game_state.show_bounding_boxes)
    {
        return;
    }
    SDL_SetRenderDraw_SDL_Color(application.renderer, GREEN);
    SDL_RenderDrawRectF(application.renderer, &entity->sprite->f_rect);

    Vec2 dis_vis_a = {entity->sprite->f_rect.x + entity->sprite->f_rect.w / 2,
                      entity->sprite->f_rect.y + entity->sprite->f_rect.h / 2};
    Vec2 dis_vis_b;

    dis_vis_b.x =
        entity->is_enemy
            ? (dis_vis_a.x + entity->atk_dst) - entity->sprite->f_rect.w / 2
            : (dis_vis_a.x - entity->atk_dst) + entity->sprite->f_rect.w / 2;

    dis_vis_b.y = dis_vis_a.y;

    SDL_SetRenderDraw_SDL_Color(application.renderer, RED);
    SDL_RenderDrawLine(application.renderer, dis_vis_a.x, dis_vis_a.y,
                       dis_vis_b.x, dis_vis_b.y);
}

void r_RenderGoodCat(Entity* self)
{
    if (!self)
    {
        return;
    }

    self->sprite->f_rect.x =
        self->position.x - (self->sprite->f_rect.w * self->sprite->scale) / 2;
    self->sprite->f_rect.y =
        self->position.y - (self->sprite->f_rect.h * self->sprite->scale);

    r_DrawSprite(application.renderer, self->sprite);

    r_DrawHealthBar(self);
    r_DrawBoundingBox(self);
}

void r_RenderBadCat(Entity* self)
{
    if (!self)
    {
        return;
    }

    self->sprite->f_rect.x =
        self->position.x - (self->sprite->f_rect.w * self->sprite->scale) / 2;
    self->sprite->f_rect.y =
        self->position.y - (self->sprite->f_rect.h * self->sprite->scale);

    r_DrawSprite(application.renderer, self->sprite);

    r_DrawHealthBar(self);
    r_DrawBoundingBox(self);
}

#define ATTACK_X_KNOCKBACK 400
#define ATTACK_Y_KNOCKBACK 200

void e_GoodCatAttack(Entity* self, Entity* other)
{
    self->position.x++;
    other->health -= 20;
    other->velocity.x = -ATTACK_X_KNOCKBACK;
    other->velocity.y = -ATTACK_Y_KNOCKBACK;
    e_SetEntityState(other, HURT);
    return;
}

void e_BadCatAttack(Entity* self, Entity* other)
{
    self->position.x--;
    other->health -= 20;
    other->velocity.x = ATTACK_X_KNOCKBACK;
    other->velocity.y = -ATTACK_Y_KNOCKBACK;
    e_SetEntityState(other, HURT);
    return;
}
