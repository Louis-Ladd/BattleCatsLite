#include "uitext.h"
#include "../log.h"

UIText* CreateUIText(float x, float y, char text_content[], TTF_Font* font,
                     SDL_Color text_color)
{
    UIText* ui_text = malloc(sizeof(*ui_text));
    ui_text->label = r_CreateLabel(application.renderer, x, y, text_content,
                                   font, text_color);
    return ui_text;
}

void SetUITextPosition(UIText* ui_text, Vec2 new_position)
{
    ui_text->label->rect.x = new_position.x;
    ui_text->label->rect.y = new_position.y;
}

void r_RenderUIText(SDL_Renderer* renderer, UIText* ui_text)
{
    r_RenderLabel(renderer, ui_text->label);
}

void DestroyUIText(UIText* ui_text)
{
    if (ui_text == NULL)
    {
        LOG_ERROR("NULL pointer passed!");
        return;
    }

    r_DestroyLabel(ui_text->label);

    free(ui_text);
}
