#ifndef IMAGE_H_
#define IMAGE_H_

#include <SDL2/SDL.h>

struct Image {
    SDL_Texture* texture;
    SDL_FRect f_rect;
};

struct Image *r_CreateImage(SDL_Renderer* renderer, SDL_Surface* image_surface, float x, float y, float w, float h);

struct Image *r_CreateNativelySizedImage(SDL_Renderer* renderer, SDL_Surface* image_surface, float x, float y);

void r_DrawImage(SDL_Renderer* renderer, struct Image* image);

void r_DestroyImage( struct Image* image );

#endif