#ifndef IMAGE_H_
#define IMAGE_H_

#include <SDL2/SDL.h>

struct Image {
    SDL_Texture* texture;
    SDL_Rect rect;
};

struct Image *r_CreateImage(SDL_Renderer* renderer, SDL_Surface* image_surface, int x, int y, int w, int h);

struct Image *r_CreateNativelySizedImage(SDL_Renderer* renderer, SDL_Surface* image_surface, int x, int y);

void r_DrawImage(SDL_Renderer* renderer, struct Image* image);

#endif