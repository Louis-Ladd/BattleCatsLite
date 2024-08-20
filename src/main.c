#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

#include "application/application.c"

const SDL_Color BLACK = {0,0,0};

int main()
{
    struct Application *application = init_application();

    TTF_Font* font;

    font = TTF_OpenFont("./noodle.ttf", 24);

    if (!application)
    {
        printf("Application failed to initalize");
        return 1;
    }
    
    SDL_Surface* text; 
    text = TTF_RenderText_Solid( font, "Battle Cats!", BLACK);
    
    SDL_Texture* text_texture;
    text_texture = SDL_CreateTextureFromSurface( application->renderer, text);
    
    SDL_Rect dest = {0, 0, 400, 400};


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

        SDL_RenderCopy( application->renderer, text_texture, NULL, &dest);
        SDL_RenderPresent( application->renderer );

    }

    return 0;
}
