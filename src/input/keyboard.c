#include "keyboard.h"

#include "../application.h"

#define MAX_KEYS 322

void HandleKeyboardInput()
{
	int keycode = application.window_event.key.keysym.sym;

	if (keycode <= 0 || keycode > MAX_KEYS)
	{
		return;
	}

	switch (application.window_event.type)
	{
		case SDL_KEYDOWN:
			application.keys[keycode] = true;
			break;
		case SDL_KEYUP:
			application.keys[keycode] = false;
			break;
	}
}

bool KeyDown(int keycode)
{
	return application.keys[keycode];
}

bool ResetKey(int keycode)
{
	int state = application.keys[keycode];
	application.keys[keycode] = false;
	return state;
}
