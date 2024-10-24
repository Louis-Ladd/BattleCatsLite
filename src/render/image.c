#include "image.h"

Image* r_CreateImage(SDL_Renderer* renderer, SDL_Surface* image_surface,
                     float x, float y, float w, float h) {
    Image* image = malloc(sizeof(*image));
    SDL_FRect rect;

    rect.w = w;
    rect.h = h;
    rect.x = x;
    rect.y = y;

    image->f_rect.x = rect.x;
    image->f_rect.y = rect.y;
    image->f_rect.w = rect.w;
    image->f_rect.h = rect.h;

    image->texture = SDL_CreateTextureFromSurface(renderer, image_surface);

    SDL_FreeSurface(image_surface);

    return image;
}

Image* r_CreateNativelySizedImage(SDL_Renderer* renderer,
                                  SDL_Surface* image_surface, float x,
                                  float y) {
    return r_CreateImage(renderer, image_surface, x, y, image_surface->w,
                         image_surface->h);
}

void r_DrawImage(SDL_Renderer* renderer, Image* image) {
    SDL_RenderCopyF(renderer, image->texture, NULL, &image->f_rect);
}

void r_DestroyImage(Image* image) {
    SDL_DestroyTexture(image->texture);
    free(image);
}
