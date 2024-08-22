#ifndef LABEL_H_
#define LABEL_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

void r_DrawLabel(int x, int y, TTF_Font* font, char text[], SDL_Renderer* renderer, SDL_Color color);

#endif