#ifndef TEXT_H_
#define TEXT_H_

#include "../render/label.h"
#include "uigeneric.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_ttf.h>

typedef struct
{
	Label* label;
} UIText;

UIText* CreateUIText(float x, float y, char text_content[], TTF_Font* font,
					 SDL_Color text_color);

void SetUITextPosition(UIText* ui_text, Vec2 new_position);

void r_RenderUIText(SDL_Renderer* renderer, UIText* ui_text);

void DestroyUIText(UIText* ui_text);

#endif
