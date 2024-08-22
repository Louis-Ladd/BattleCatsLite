#include "main.h"

int main()
{
    struct Application *application = init_application();

    TTF_Font* font;

    font = TTF_OpenFont("assets/noodle.ttf", 150);


    if (!application)
    {
        printf("Application failed to initalize");
        return 1;
    }

    SDL_SetRenderDrawColor(application->renderer, 0, 0, 127, 0);

    SDL_RenderClear(application->renderer);
    
    SDL_RenderPresent(application->renderer);

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

        SDL_RenderPresent( application->renderer ); // Flips our double buffer
    }

    return 0;
}
