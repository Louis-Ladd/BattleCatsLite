#include "uibutton.h"
#include "../application.h"
#include "../log.h"

UIButton* CreateButton(float x, float y, float w, float h, char button_text[],
                       SDL_Color button_color, SDL_Color text_color)
{
    UIButton* button = malloc(sizeof(*button));

    button->color = button_color;

    button->label =
        r_CreateLabel(application.renderer, x + 5, y + (h / 2), button_text,
                      application.fonts[LARGE_FONT], text_color);

    SDL_FRect button_rect = {x, y, w, h};

    button->f_rect = button_rect;

    button->onClick = NULL;

    return button;
}

void SetButtonFuncPointer(UIButton* ui_button, void (*f)(void))
{
    ui_button->onClick = f;
}

void r_RenderUIButton(SDL_Renderer* renderer, UIButton* ui_button)
{
    SDL_SetRenderDraw_SDL_Color(renderer, ui_button->color);
    SDL_RenderFillRectF(renderer, &ui_button->f_rect);
    r_RenderLabel(renderer, ui_button->label);
    SDL_SetRenderDraw_SDL_Color(
        renderer, BLACK); // Whenever we're done rendering something, we clean
                          // up by setting draw color to black.
}

void DestroyUIButton(UIButton* button)
{
    if (button == NULL)
    {
        LOG_ERROR("Null pointer passed!");
        return;
    }
    r_DestroyLabel(button->label);

    free(button);
}
