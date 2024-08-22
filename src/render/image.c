#include <SDL2/SDL.h>

struct Image {
    SDL_Texture* texture;
    SDL_Rect* rect;
};

struct Image *create_image(SDL_Surface* image_surface, int x, int y, int native_size, int w, int h)
{
    struct Image* image = malloc(sizeof(struct Image));
    SDL_Surface* surface = image_surface; 
    SDL_Rect rect;

    if (native_size)
    {
        SDL_Rect rect = {x, y, 100, 100};    
    }
    else if (x != NULL && y != NULL)
    {
        SDL_Rect rect = {x, y, w, h};
    }
    else 
    {
        return NULL;
    }

    image->rect = rect;

    return image;
}