#ifndef BUTTON_H_
#define BUTTON_H_

#include "../application/application.h"
#include "../render/label.h"
#include "../color.h"

typedef struct {
    Label* label;
    SDL_Color color;
    SDL_FRect f_rect;
    void (*on_click)(void); // I have a very interesting journy ahead of me...
} Button;

Button* CreateButton(Application* app, float x, float y, float w, float h, SDL_Color color);

void r_RenderButton(SDL_Renderer* renderer, Button* button);

void DestroyButton(Button* button);

#endif
