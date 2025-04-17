#ifndef UIRENDER_H_
#define UIRENDER_H_

#include "../render/label.h"
#include "text.h"
#include "uigeneric.h"

void ui_RenderText(SDL_Renderer* renderer, GenericUIElement* element);

void ui_RenderButton(SDL_Renderer* renderer, GenericUIElement* element);

#endif
