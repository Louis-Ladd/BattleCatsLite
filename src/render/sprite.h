#ifndef SPRITE_H_
#define SPRITE_H_

#include "../utils/types.h"
#include "image.h"
#include "sprite_enum.h"
#include <SDL2/SDL.h>

typedef struct
{
    u8 sprite_offset;
    u8 animation_frame;
    u32 last_animation_update;
    Image* sprite_sheet;
    SDL_FRect f_rect;
    float scale;
} Sprite;

Sprite* r_CreateSprite(int sprite_offset, Image* sprice_sheet, float x, float y,
                       float scale);

void r_DrawSprite(SDL_Renderer* renderer, Sprite* sprite);

void r_DestroySprite(Sprite* sprite);

#endif
