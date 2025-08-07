#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include <SDL2/SDL_events.h>
#include <stdbool.h>

void HandleKeyboardInput();

bool KeyDown(int keycode);

bool ResetKey(int keycode);

#endif
