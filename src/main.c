#include <SDL2/SDL.h>
#include <stdbool.h>

#include "application/application.c"

int main()
{
    struct Application *application = init_application();

    if (!application)
    {
        printf("Application failed to initalize");
        return 1;
    }

    while(application->is_running)
    {
        while(SDL_PollEvent(&application->window_event) > 0)
        {
            switch (application->window_event.type)
            {
                case SDL_QUIT:
                    application->is_running = false;
                    break;
            }
            SDL_UpdateWindowSurface(application->window);
        }
    }

    return 0;
}
