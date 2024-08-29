#include "sprite.h"

const int SPRITE_SIZE = 256;
const int COLUMNS = 2560 / SPRITE_SIZE;
const int ROWS = 2560 / SPRITE_SIZE;

//Writing this code made me thirsty for a sprite 

Sprite *r_CreateSprite(int sprite_offset, float x, float y, float scale)
{
    Sprite* sprite = malloc(sizeof(Sprite));
    sprite->sprite_offset = sprite_offset; 
    SDL_FRect cat_frect = {x, y, 256*scale, 256*scale};
    sprite->f_rect = cat_frect;

    return sprite;
}

void r_DrawSprite(SDL_Renderer* renderer, Image *sprite_sheet, Sprite *sprite)
{
    SDL_Rect sprite_rect;

    sprite_rect.w = SPRITE_SIZE;
    sprite_rect.h = SPRITE_SIZE;
    sprite_rect.x = (sprite->sprite_offset % COLUMNS) * 256; // Change this to dynamicly fetch sprite sheet size!!!
    sprite_rect.y = (sprite->sprite_offset / ROWS) * 256;

    SDL_RenderCopyF(renderer, sprite_sheet->texture, &sprite_rect, &sprite->f_rect);
}

void r_DestroySprite(Sprite* sprite)
{
    free(sprite);
}