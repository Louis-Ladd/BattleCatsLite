#ifndef SPRITE_H_
#define SPRITE_H_

#include <SDL2/SDL.h>
#include "image.h"
#include "cat_enum.h"

struct Sprite {
    enum CatSpriteOffset sprite_offset;
    SDL_FRect f_rect;
    float scale;
};

struct Sprite *r_CreateSprite(int sprite_offset, float x, float y, float scale);

void r_DrawSprite(SDL_Renderer* renderer, struct Image *sprite_sheet, struct Sprite *sprite);


#endif