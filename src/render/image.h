#ifndef IMAGE_H_
#define IMAGE_H_

#include <SDL2/SDL.h>

typedef struct
{
    SDL_Texture* texture;
    SDL_FRect f_rect;
} Image;

Image* r_CreateImage(SDL_Renderer* renderer, SDL_Surface* image_surface,
                     float x, float y, float w, float h);

Image* r_CreateNativelySizedImage(SDL_Renderer* renderer,
                                  SDL_Surface* image_surface, float x, float y);

void r_DrawImage(SDL_Renderer* renderer, Image* image);

void r_DestroyImage(Image* image);

#endif
