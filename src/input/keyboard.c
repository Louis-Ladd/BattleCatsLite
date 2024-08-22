#include "keyboard.h"

#define MAX_KEYS 322

void HandleKeyboardInput(struct Application* app) 
{
    int keycode = app->window_event.key.keysym.sym;

    if (keycode <= 0 || keycode > MAX_KEYS) 
    { 
       return;
    } 
    switch (app->window_event.type)
    {
        case SDL_KEYDOWN:
            app->keys[keycode] = true;
            break;
        case SDL_KEYUP:
            app->keys[keycode] = false;
            break;
    }
}
