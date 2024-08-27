#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

struct Application {
  SDL_Window *window;
  SDL_Surface *window_surface;
  SDL_Renderer *renderer;
  SDL_Event window_event;
  bool is_running;
  bool keys[322];
  float delta_time;
};

struct Application *InitApplication();

#endif