#include "uitext.h"
#include "../application.h"
#include "../log.h"

UIText* CreateUIText(float x, float y, char text_content[], TTF_Font* font,
					 SDL_Color text_color)
{
	UIText* ui_text = malloc(sizeof(*ui_text));

	if (!ui_text)
	{
		LOG_ERROR("Failed to allocate memory for UIText!");
		return NULL;
	}

	ui_text->label = r_CreateLabel(application.renderer, x, y, text_content,
								   font, text_color);

	if (!ui_text->label)
	{
		LOG_ERROR("Something went wrong creating a UITexts' label!");
		return NULL;
	}

	return ui_text;
}

void SetUITextPosition(UIText* ui_text, Vec2 new_position)
{
	ui_text->label->f_rect.x = new_position.x;
	ui_text->label->f_rect.y = new_position.y;
}

void r_RenderUIText(SDL_Renderer* renderer, UIText* ui_text)
{
	r_RenderLabel(renderer, ui_text->label);
}

void DestroyUIText(UIText* ui_text)
{
	if (!ui_text)
	{
		LOG_ERROR("NULL passed to destroy!");
		return;
	}

	r_DestroyLabel(ui_text->label);

	free(ui_text);
}
