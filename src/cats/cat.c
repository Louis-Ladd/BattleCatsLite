#include "cat.h"
#include "../log.h"

Entity* e_CreateGenericGoodCat(EntityID id, Image* sprite_sheet) {
    Sprite* sprite = r_CreateSprite(0, sprite_sheet, 1280.0f, 700.0f, 1.0f);
    Entity* cat = e_CreateEntity(id, sprite, 0, 100, false, e_UpdateGoodCat);
    cat->speed = 50;

    return cat;
}

Entity* e_CreateGenericBadCat(EntityID id, Image* sprite_sheet) {
    Sprite* sprite = r_CreateSprite(1, sprite_sheet, 0.0f, 700.0f, 1.0f);
    Entity* cat = e_CreateEntity(id, sprite, 0, 100, true, e_UpdateBadCat);
    cat->speed = 50;

    return cat;
}

void e_UpdateGoodCat(Entity* self, Entity* other) {
    other->current_frame = 0;
    if (fabs(self->velocity.x) < self->speed) {
        self->velocity.x -= 10.0f;
    }

    if (self == other) {
        return;
    }

    if (DistanceVec2(self->position, other->position) < 200) {
        LOG("Good cat attacking entity with ID %i", other->id);
        e_GoodCatAttack(self, other);
    }

    return;
}

void e_UpdateBadCat(Entity* self, Entity* other) {
    other->current_frame = 0;
    if (fabs(self->velocity.x) < self->speed) {
        self->velocity.x += 10.0f;
    }

    if (self == other) {
        return;
    }

    if (DistanceVec2(self->position, other->position) < 200) {
        e_BadCatAttack(self, other);
    }

    return;
}

void e_GoodCatAttack(Entity* self, Entity* other) {
    self->position.x++;
    other->health--;
    other->velocity.x = -1600;
    other->velocity.y = -600;
    return;
}

void e_BadCatAttack(Entity* self, Entity* other) {
    self->position.x--;
    other->health--;
    other->velocity.x = 400;
    other->velocity.y = -600;
    return;
}
