#ifndef LABEL_H_
#define LABEL_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct {
    char* text;
    SDL_FRect rect;
    SDL_Color color;
    TTF_Font* font;
    SDL_Texture* texture;
} Label;

void r_DrawText(int x, int y, TTF_Font* font, char text[],
                SDL_Renderer* renderer, SDL_Color color);

Label* r_CreateLabel(SDL_Renderer* renderer, float x, float y, char text[],
                     TTF_Font* font, SDL_Color color);

void r_UpdateLabel();

void r_RenderLabel(SDL_Renderer* renderer, Label* label);

void r_DestroyLabel(Label* label);

#endif
