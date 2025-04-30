#include "sprite.h"
#include "../log.h"
#include <SDL2/SDL_timer.h>

const int SPRITE_SIZE = 256;
const int COLUMNS = 2560 / SPRITE_SIZE;
const int ROWS = 2560 / SPRITE_SIZE;

// Writing this code made me thirsty for a sprite

Sprite* r_CreateSprite(int sprite_offset, Image* sprite_sheet, float x, float y,
                       float scale)
{
    Sprite* sprite = malloc(sizeof(*sprite));

    if (!sprite)
    {
        LOG_ERROR("Failed to allocate memory for sprite!");
        return NULL;
    }

    sprite->sprite_sheet = sprite_sheet;
    sprite->sprite_offset = sprite_offset * 10;
    sprite->last_animation_update = SDL_GetTicks();
    sprite->animation_frame = 0;
    sprite->scale = scale;

    SDL_FRect sprite_frect = {x, y, 256 * scale, 256 * scale};

    sprite->f_rect = sprite_frect;

    return sprite;
}

void r_DrawSprite(SDL_Renderer* renderer, Sprite* sprite)
{
    SDL_Rect sprite_rect;

    sprite_rect.w = SPRITE_SIZE;
    sprite_rect.h = SPRITE_SIZE;
    sprite_rect.x = sprite->animation_frame * 256;
    sprite_rect.y = (sprite->sprite_offset / 10) * 256;

    SDL_RenderCopyF(renderer, sprite->sprite_sheet->texture, &sprite_rect,
                    &sprite->f_rect);
}

void r_DestroySprite(Sprite* sprite) { free(sprite); }
