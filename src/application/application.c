#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

struct Application {
  SDL_Window *window;
  SDL_Surface *window_surface;
  SDL_Renderer *renderer;
  SDL_Event window_event;
  bool is_running;
};

struct Application *init_application()
{
  struct Application *app = malloc(sizeof(struct Application)); 

  app->is_running = true;

  if(SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("Failed to initialize the SDL2 library\n");
    return NULL;
  }

  if ( TTF_Init() < 0 )
  {
    printf("Failed to initialize fonts\n");
    return NULL;
  }

  app->window = SDL_CreateWindow("Battle Cats!",
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  680, 480,
                                  0);

  if(!app->window)
  {
    printf("Failed to create window\n");
    return NULL;
  }

  app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_SOFTWARE);

  if (!app->renderer)
  {
    printf("Failed to create renderer\n");
    return NULL;
  }

  return app;
} 
