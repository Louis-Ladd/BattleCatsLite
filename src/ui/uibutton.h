#ifndef BUTTON_H_
#define BUTTON_H_

#include "../color.h"
#include "../render/label.h"
#include "uigeneric.h"

typedef struct
{
	Label* label;
	SDL_Color color;
	SDL_FRect f_rect;
	void (*onClick)();
} UIButton;

UIButton* CreateUIButton(float x, float y, float w, float h, char button_text[],
						 SDL_Color button_color, SDL_Color text_color);

void SetUIButtonFuncPointer(UIButton* button, void (*f)(void));

void r_RenderUIButton(SDL_Renderer* renderer, UIButton* button);

void HandleButtonClick(UIButton* button);

void DestroyUIButton(UIButton* button);

#endif
