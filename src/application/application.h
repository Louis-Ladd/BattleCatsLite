#ifndef APPLICATION_H_
#define APPLICATION_H_

#define SCREEN_WIDTH 1280 
#define SCREEN_HEIGHT 720 

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

enum FontEnum {
  SMALL_FONT,
  MEDIUM_FONT,
  LARGE_FONT,
  XLARGE_FONT
};

enum ContextEnum {
  MAIN_MENU,
  LEVEL_ONE,
  LEVEL_TWO
};

typedef struct {
  SDL_Window* window;
  SDL_Surface* window_surface;
  SDL_Renderer* renderer;
  SDL_Event window_event;
  bool is_running;
  bool keys[322];
  TTF_Font* fonts[4];
  float delta_time;
  int current_context;
  int fps;
  int timer;
} Application;

Application *InitApplication();

#endif