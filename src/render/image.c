#include <SDL2/SDL.h>

struct Image {
    SDL_Texture* texture;
    SDL_Rect rect;
};

struct Image *r_CreateImage(SDL_Surface* image_surface, int x, int y, int w, int h)
{
    struct Image* image = malloc(sizeof(struct Image));
    SDL_Surface* surface = image_surface; 
    SDL_Rect rect;

    rect.w = 100;
    rect.h = 100;

    image->rect.w = rect.w;
    image->rect.h = rect.h;

    return image;
}

struct Image *r_CreateNativelySizedImage(SDL_Surface* image_surface, int x, int y)
{
    //TODO: get native size of image lol
    return r_CreateImage(image_surface, x, y, 100, 100);
}