#ifndef UIMAGE_H_
#define UIMAGE_H_

#include "../render/image.h"
#include "uigeneric.h"
#include <SDL2/SDL_surface.h>

typedef struct
{
    Image* image;
    SDL_FRect f_rect;
} UIImage;

UIImage* CreateUIImage(SDL_Surface image_surface, float x, float y, float w,
                       float h);

void DestroyUIImage(UIImage* ui_image);

#endif
