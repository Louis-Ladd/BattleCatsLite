#include "main.h"

int main()
{
    struct Application *application = InitApplication();

    TTF_Font* font;

    font = TTF_OpenFont("assets/noodle.ttf", 125);


    if (!application)
    {
        printf("Application failed to initalize");
        return 1;
    }

    SDL_SetRenderDraw_SDL_Color(application->renderer, RED);

    SDL_RenderClear(application->renderer);
    
    SDL_RenderPresent(application->renderer);

    r_DrawLabel(50, 50, font, "Battle Cats!", application, BLUE);


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
