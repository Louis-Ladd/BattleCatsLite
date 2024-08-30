#include "mouse.h"

#if SDL_VERSION_ATLEAST(2, 0, 22)
    //Why the hell doesn't ubuntu's pre-built SDL2 package not have this?
#else
SDL_FORCE_INLINE SDL_bool SDL_PointInFRect(const SDL_FPoint *p, const SDL_FRect *r)
{
    return ( (p->x >= r->x) && (p->x < (r->x + r->w)) &&
             (p->y >= r->y) && (p->y < (r->y + r->h)) ) ? SDL_TRUE : SDL_FALSE;
}
#endif

void HandleMouseInputMainMenu(Application* app, MainMenu* menu)
{
    if (app->window_event.type != SDL_MOUSEBUTTONDOWN)
    { return; }

    SDL_FPoint mouse_position;

    mouse_position.x = app->window_event.motion.x; 
    mouse_position.y = app->window_event.motion.y;

    for (int i = 0; i < MAX_BUTTON_COUNT; i++)
    {
        if (!menu->buttons[i])
        { continue; }

        if (!SDL_PointInFRect(&mouse_position, &menu->buttons[i]->f_rect))
        { continue; }
        
        if (menu->buttons[i]->onClick)
        {
            menu->buttons[i]->onClick(app);
        }
        printf("Clicked on: %s\n", menu->buttons[i]->label->text);
    }

}