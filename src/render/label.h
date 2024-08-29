#ifndef LABEL_H_
#define LABEL_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

struct Label {
    char* text;
    SDL_FRect rect;
    SDL_Color color;
    TTF_Font* font;
    SDL_Texture* texture;
};

void r_DrawText(int x, int y, TTF_Font* font, char text[], SDL_Renderer* renderer, SDL_Color color);

struct Label *r_CreateLabel(SDL_Renderer* renderer, float x, float y, char text[], TTF_Font* font, SDL_Color color);

void r_UpdateLabel();

void r_RenderLabel(SDL_Renderer* renderer, struct Label* label);

void r_DestroyLabel(struct Label* label);

#endif