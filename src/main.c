#include "main.h"

int main()
{
    struct Application *app = InitApplication();

    TTF_Font* font;

    font = TTF_OpenFont("assets/noodle.ttf", 125);


    if (!app)
    {
        printf("Application failed to initalize");
        return 1;
    }

    struct Image *cat = r_CreateImage(app->renderer, IMG_Load("assets/cat.png"), 50, 50, 100, 100);


    
    SDL_RenderPresent(app->renderer);


    while(app->is_running)
    {

        while(SDL_PollEvent(&app->window_event) > 0)
        {
            switch (app->window_event.type)
            {
                case SDL_QUIT:
                    app->is_running = false;
                    break;
            }
        }

        SDL_SetRenderDraw_SDL_Color(app->renderer, DARK_BLUE);
        SDL_RenderClear(app->renderer);


        r_DrawImage(app->renderer, cat);
        if (cat->rect.x < 1000)
        {
            cat->rect.x += 1;
        }
        SDL_RenderPresent( app->renderer ); // Flips our double buffer
    }

    return 0;
}
