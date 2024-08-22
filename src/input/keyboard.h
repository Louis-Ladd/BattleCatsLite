#ifndef KEYBOARD_H_ 
#define KEYBOARD_H_

#include <SDL2/SDL_events.h>
#include <stdbool.h>

#include "../application/application.h"

void HandleKeyboardInput(struct Application* app);

#endif