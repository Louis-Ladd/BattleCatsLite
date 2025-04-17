#ifndef TEXT_H_
#define TEXT_H_

#include "../render/label.h"
#include "uigeneric.h"
#include <SDL2/SDL_rect.h>

typedef struct
{
    Label* label;
    SDL_FRect f_rect;
} UIText;

UIText* CreateText(float x, float y, float w, float h, char text_content[],
                   SDL_Color text_color);

void r_RenderUIText(SDL_Renderer* renderer, UIText* text);

#endif
