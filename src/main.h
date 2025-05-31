#ifndef MAIN_H_
#define MAIN_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

#include "color.h"
#include "input/keyboard.h"
#include "input/mouse.h"
#include "log.h"
#include "render/image.h"
#include "render/label.h"
#include "render/sprite.h"
#include "render/sprite_enum.h"
#include "scene/scene_manager.h"
#include "utils/util.h"

// Levels and menus
#include "levels/level.h"
#include "main_menu/main_menu.h"

int main();

void main_context_loop();

void handle_events();

#endif
