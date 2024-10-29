#ifndef CAT_H_
#define CAT_H_

#include "../entity/entity.h"
#include <SDL2/SDL_render.h>

Entity* e_CreateGenericGoodCat(Image* sprite_sheet);

Entity* e_CreateGenericBadCat(Image* sprite_sheet);

void e_UpdateGoodCat(Entity* self, Entity* other);

void e_UpdateBadCat(Entity* self, Entity* other);

void e_RenderGoodCat(Entity* self);

void e_RenderBadCat(Entity* self);

void e_GoodCatAttack(Entity* self, Entity* other);

void e_BadCatAttack(Entity* self, Entity* other);

#endif
