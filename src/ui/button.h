#ifndef BUTTON_H_
#define BUTTON_H_

#include "../render/label.h"
#include "../color.h"

typedef struct {
    Label* label;
    SDL_Color color;
    SDL_FRect f_rect;
    void (*onClick)();
} Button;

Button* CreateButton(float x, float y, float w, float h, char button_text[], SDL_Color button_color, SDL_Color text_color);

void SetButtonFuncPointer(Button* button, void (*f)(void));

void r_RenderButton(SDL_Renderer* renderer, Button* button);

void DestroyButton(Button* button);

#endif
