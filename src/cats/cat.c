#include "cat.h"

Entity* e_CreateGenericGoodCat(EntityID id, Image* sprite_sheet)
{
    Sprite* sprite = r_CreateSprite(0, sprite_sheet, 1150.0f, 50.0f, 1.0f);
    Entity* cat = e_CreateEntity(id, sprite, 0, 100, false);

    return cat;
}

Entity* e_CreateGenericBadCat(EntityID id, Image* sprite_sheet)
{
    Sprite* sprite = r_CreateSprite(1, sprite_sheet, 50.0f, 50.0f, 1.0f);
    Entity* cat = e_CreateEntity(id, sprite, 0, 100, true);

    return cat;
}

void e_UpdateGoodCat(Entity* self, Entity* other)
{
    other->current_frame = 0;
    if (fabs(self->velocity.x) < self->speed)
    {
        self->velocity.x -= 10.0f;
    }
    return;
}

void e_UpdateBadCat(Entity* self, Entity* other)
{
    other->current_frame = 0;
    if (fabs(self->velocity.x) < self->speed)
    {
        self->velocity.x += 10.0f;
    }
    return;
}
