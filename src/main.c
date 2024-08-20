#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

#include "render/label.c"

int main()
{
    struct Application *application = init_application();

    TTF_Font* font;

    font = TTF_OpenFont("src/noodle.ttf", 200);

    if (!application)
    {
        printf("Application failed to initalize");
        return 1;
    }

    draw_label(50, 50, font, "Battle Cats!", application);

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
        }

        SDL_UpdateWindowSurface(application->window);
        SDL_RenderPresent( application->renderer );

    }

    return 0;
}
