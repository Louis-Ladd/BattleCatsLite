#ifndef COLOR_H_
#define COLOR_H_

#include <SDL2/SDL_pixels.h>

#define SDL_SetRenderDraw_SDL_Color(renderer, color) \
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a)

extern const SDL_Color BLACK;
extern const SDL_Color WHITE;
extern const SDL_Color RED;
extern const SDL_Color GREEN;
extern const SDL_Color BLUE;
extern const SDL_Color DARK_BLUE;
extern const SDL_Color CYAN;
extern const SDL_Color MAGENTA;
extern const SDL_Color BROWN;
extern const SDL_Color ORANGE;

#endif