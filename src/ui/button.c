#include "button.h"

#include "../application.h"

Button* CreateButton(float x, float y, float w, float h, char button_text[], SDL_Color button_color, SDL_Color text_color)
{
    Button* button = malloc(sizeof(*button));

    button->color = button_color;

    button->label = r_CreateLabel(application.renderer, x + 5, y + (h/2), button_text, application.fonts[LARGE_FONT], text_color);

    SDL_FRect button_rect = {x, y, w, h};

    button->f_rect = button_rect;

    button->onClick = NULL;

    return button;
}

void SetButtonFuncPointer(Button* button, void (*f)(void))
{
    button->onClick = f;
}

void r_RenderButton(SDL_Renderer* renderer, Button* button)
{
    SDL_SetRenderDraw_SDL_Color(renderer, button->color);
    SDL_RenderFillRectF(renderer, &button->f_rect);
    r_RenderLabel(renderer, button->label);
    SDL_SetRenderDraw_SDL_Color(renderer, BLACK); //Whenever we're done rendering something, we clean up by setting draw color to black.
}
