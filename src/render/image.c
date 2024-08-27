#include "image.h"

struct Image *r_CreateImage(SDL_Renderer* renderer, SDL_Surface* image_surface, float x, float y, float w, float h)
{
    struct Image* image = malloc(sizeof(struct Image));
    SDL_Surface* surface = image_surface; 
    SDL_Rect rect;

    rect.w = 100.f;
    rect.h = 100.f;
    rect.x = x;
    rect.y = y;

    image->rect.x = rect.x;
    image->rect.y = rect.y;
    image->rect.w = rect.w;
    image->rect.h = rect.h;

    image->texture = SDL_CreateTextureFromSurface(renderer, surface);


    SDL_FreeSurface(surface);

    return image;
}

struct Image *r_CreateNativelySizedImage(SDL_Renderer* renderer, SDL_Surface* image_surface, float x, float y)
{
    return r_CreateImage(renderer, image_surface, x, y, 100, 100);
}

void r_DrawImage(SDL_Renderer* renderer, struct Image* image)
{
    SDL_RenderCopyF(renderer, image->texture, NULL, &image->rect);
}