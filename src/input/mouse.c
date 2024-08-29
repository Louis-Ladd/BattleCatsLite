#include "mouse.h"

void HandleMouseInputMainMenu(SDL_Event event, MainMenu* menu)
{
    if (event.type != SDL_MOUSEBUTTONDOWN)
    { return; }

    SDL_FPoint mouse_position;

    mouse_position.x = event.motion.x; 
    mouse_position.y = event.motion.y;

    for (int i = 0; i < MAX_BUTTON_COUNT; i++)
    {
        if (!menu->buttons[i])
        { continue; }

        if (SDL_PointInFRect(&mouse_position, &menu->buttons[i]->f_rect))
        {
            printf("Clicked on: %s\n", menu->buttons[i]->label->text);
        }
    }

}