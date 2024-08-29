#ifndef MOUSE_H_
#define MOUSE_H_

#include <SDL2/SDL_events.h>

#include "../application/application.h"
#include "../main_menu/main_menu.h"

void HandleMouseInputMainMenu(SDL_Event event, MainMenu* menu);

#endif
