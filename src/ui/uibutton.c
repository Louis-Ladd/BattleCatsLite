#include "uibutton.h"
#include "../application.h"
#include "../log.h"
#include "SDL2/SDL_render.h"
#include <string.h>

UIButton* CreateUIButton(float x, float y, float w, float h, char button_text[],
                         SDL_Color button_color, SDL_Color text_color)
{
    LOG_DEBUG("Creating UI Button...");
    UIButton* button = malloc(sizeof(*button));

    if (!button)
    {
        LOG_ERROR("Failed to allocate memory for UIButton!");
        return NULL;
    }

    button->color = button_color;

    button->label =
        r_CreateLabel(application.renderer, x + (w / 2), y + (h / 2),
                      button_text, application.fonts[LARGE_FONT], text_color);

    if (!button->label)
    {
        LOG_ERROR("Something went wrong creating UIButtons' label!");
        return NULL;
    }

    int label_width, label_height = 0;

    SDL_QueryTexture(button->label->texture, NULL, NULL, &label_width,
                     &label_height);

    button->label->rect.x = x + (w / 2) - (int)(label_width / 2);
    button->label->rect.y = y + (h / 2) - (int)(label_height / 2);

    SDL_FRect button_rect = {x, y, w, h};

    button->f_rect = button_rect;

    button->onClick = NULL;

    return button;
}

void SetUIButtonFuncPointer(UIButton* ui_button, void (*f)(void))
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
    if (!button)
    {
        LOG_ERROR("NULL passed to destroy!");
        return;
    }
    r_DestroyLabel(button->label);

    free(button);
}
