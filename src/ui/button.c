#include "button.h"

struct Button* CreateButton(struct Application* app, float x, float y, float w, float h, SDL_Color color)
{
    struct Button* button = malloc(sizeof(struct Button));

    button->label = r_CreateLabel(app->renderer, x + (w/2), y + (h/2), "Text :D", app->fonts[SMALL_FONT], color);

    SDL_FRect button_rect = {x, y, w, h};

    button->f_rect = button_rect;

    return button;
}

void r_RenderButton(SDL_Renderer* renderer, struct Button* button)
{
    r_RenderLabel(renderer, button->label); 

    SDL_SetRenderDraw_SDL_Color(renderer, button->color);
    SDL_RenderFillRectF(renderer, &button->f_rect);
    SDL_SetRenderDraw_SDL_Color(renderer, BLACK); //Whenever we're done rendering something, we clean up by setting draw color to black. 
}