#ifndef BUTTON_H_
#define BUTTON_H_

#include "../application/application.h"
#include "../render/label.h"
#include "../color.h"

struct Button {
    struct Label* label;
    SDL_Color color;
    SDL_FRect f_rect;
};

struct Button* CreateButton(struct Application* app, float x, float y, float w, float h, SDL_Color color);

void r_RenderButton(SDL_Renderer* renderer, struct Button* button);

void DestroyButton(struct Button* button);

#endif
