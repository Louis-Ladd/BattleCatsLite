#include "application.h"

Application *InitApplication()
{
  Application *app = malloc(sizeof(Application)); 

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

  app->fonts[SMALL_FONT] = TTF_OpenFont("assets/noodle.ttf", 16);
  app->fonts[MEDIUM_FONT] = TTF_OpenFont("assets/noodle.ttf", 32);
  app->fonts[LARGE_FONT] = TTF_OpenFont("assets/noodle.ttf", 64);  
  app->fonts[XLARGE_FONT] = TTF_OpenFont("assets/noodle.ttf", 128);

  if (IMG_Init(IMG_INIT_PNG) < 0)
  {
    printf("Failed ot initialize SDL2 Image library\n");
    return NULL;
  }

  app->window = SDL_CreateWindow("Battle Cats!",
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  SCREEN_WIDTH, SCREEN_HEIGHT,
                                  0);

  if(!app->window)
  {
    printf("Failed to create window\n");
    return NULL;
  }

  SDL_SetWindowResizable(app->window, SDL_FALSE);

  app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_SOFTWARE);

  if (!app->renderer)
  {
    printf("Failed to create renderer\n");
    return NULL;
  }

  app->delta_time = 0.f;
  app->timer = 0;

  app->current_context = MAIN_MENU;

  return app;
} 
