#ifndef CAT_H_
#define CAT_H_

#include "../entity/entity.h"
#include <SDL2/SDL_render.h>

Entity* e_CreateGenericGoodCat(EntityID id, Image* sprite_sheet);

Entity* e_CreateGenericBadCat(EntityID id, Image* sprite_sheet);

void e_UpdateGoodCat(Entity* self, Entity* other);

void e_UpdateBadCat(Entity* self, Entity* other);

#endif
