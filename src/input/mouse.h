#ifndef MOUSE_H_
#define MOUSE_H_

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_version.h>

#include "../main_menu/main_menu.h"
#include "../ui/uimanager.h"

void HandleMouseInput(GenericUIElementList* element_list,
                      SDL_MouseMotionEvent mouse_event);

#endif
