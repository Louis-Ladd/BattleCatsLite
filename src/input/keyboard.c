#include "keyboard.h"

void HandleKeyboardInput(struct Application* app) 
{
    switch (app->window_event.type)
    {
        case SDL_KEYDOWN:
            app->keys[app->window_event.key.keysym.sym] = true;
            break;
        case SDL_KEYUP:
            app->keys[app->window_event.key.keysym.sym] = false;
            break;
    }
}