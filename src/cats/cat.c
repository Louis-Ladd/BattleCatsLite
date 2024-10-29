#include "cat.h"
#include "../application.h"
#include "../color.h"
#include "../log.h"

Entity* e_CreateGenericGoodCat(Image* sprite_sheet) {
    Sprite* sprite = r_CreateSprite(0, sprite_sheet, 1280.0f, 700.0f, 1.0f);
    Entity* cat = e_CreateEntity(0, sprite, 0, 100, false, e_UpdateGoodCat,
                                 r_RenderGoodCat);
    cat->speed = 100;

    return cat;
}

Entity* e_CreateGenericBadCat(Image* sprite_sheet) {
    Sprite* sprite = r_CreateSprite(1, sprite_sheet, 0.0f, 700.0f, 1.0f);
    Entity* cat =
        e_CreateEntity(0, sprite, 0, 100, true, e_UpdateBadCat, r_RenderBadCat);
    cat->speed = 100;

    return cat;
}

bool e_LifeUpdate(Entity* entity) {
    if (entity->health <= 0 && entity) {
        RemoveEntity(application.scene_manager->scenes[0], entity);
        return true;
    }
    return false;
}

void e_UpdateGoodCat(Entity* self, Entity* other) {
    if (e_LifeUpdate(self)) {
        return;
    }

    other->current_frame = 0;
    if (fabs(self->velocity.x) < self->speed) {
        self->velocity.x -= 10.0f;
    }

    if (self == other) {
        return;
    }

    if (DistanceVec2(self->position, other->position) < 200 &&
        other->is_enemy) {
        LOG("Good cat attacking entity with ID %i", other->id);
        e_GoodCatAttack(self, other);
    }

    return;
}

void e_UpdateBadCat(Entity* self, Entity* other) {
    if (e_LifeUpdate(self)) {
        return;
    }

    other->current_frame = 0;
    if (fabs(self->velocity.x) < self->speed) {
        self->velocity.x += 10.0f;
    }

    if (self == other) {
        return;
    }

    if (DistanceVec2(self->position, other->position) < 200 &&
        !other->is_enemy) {
        e_BadCatAttack(self, other);
    }

    return;
}

void r_DrawHealthBar(Entity* entity) {
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
}

void r_RenderGoodCat(Entity* self) {
    if (!self) {
        return;
    }

    self->sprite->f_rect.x =
        self->position.x - (self->sprite->f_rect.w * self->sprite->scale) / 2;
    self->sprite->f_rect.y =
        self->position.y - (self->sprite->f_rect.h * self->sprite->scale);

    r_DrawSprite(application.renderer, self->sprite);

    r_DrawHealthBar(self);
}

void r_RenderBadCat(Entity* self) {
    if (!self) {
        return;
    }

    self->sprite->f_rect.x =
        self->position.x - (self->sprite->f_rect.w * self->sprite->scale) / 2;
    self->sprite->f_rect.y =
        self->position.y - (self->sprite->f_rect.h * self->sprite->scale);

    r_DrawSprite(application.renderer, self->sprite);
}

void e_GoodCatAttack(Entity* self, Entity* other) {
    self->position.x++;
    other->health -= 80;
    other->velocity.x = -1200;
    other->velocity.y = -900;
    return;
}

void e_BadCatAttack(Entity* self, Entity* other) {
    self->position.x--;
    other->health -= 80;
    other->velocity.x = 1200;
    other->velocity.y = -900;
    return;
}
