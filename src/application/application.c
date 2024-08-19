#include <SDL2/SDL.h>
#include <stdbool.h>

struct Application {
    SDL_Window *window;
    SDL_Surface *window_surface;
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

    app->window_surface = SDL_GetWindowSurface(app->window);

    if(!app->window_surface)
    {
        printf("Failed to get the surface from the window\n");
        return NULL;
    }

    return app;

} 
