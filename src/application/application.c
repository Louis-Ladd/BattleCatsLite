#include "application.h"

struct Application *InitApplication()
{
  struct Application *app = malloc(sizeof(struct Application)); 

  for (int i = 0; i < 322; i++)
  {
    app->keys[i] = false;
  }

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

  if (IMG_Init(IMG_INIT_PNG) < 0)
  {
    printf("Failed ot initialize SDL2 Image library\n");
    return NULL;
  }

  app->window = SDL_CreateWindow("Battle Cats!",
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  1200, 480,
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
