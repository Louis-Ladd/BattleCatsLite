#include "main.h"

int main()
{
    struct Application* app = InitApplication();

    TTF_Font* font;

    font = TTF_OpenFont("assets/noodle.ttf", 125);

    if (!app)
    {
        printf("Application failed to initalize");
        return 1;
    }

    struct Image* cat = r_CreateImage(app->renderer, IMG_Load("assets/cat.png"), 50, 50, 100, 100);

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
                case SDL_KEYDOWN:
                    HandleKeyboardInput( app );
                    break;
                case SDL_KEYUP:
                    HandleKeyboardInput( app );
                    break;
            }
        }

        SDL_SetRenderDraw_SDL_Color(app->renderer, DARK_BLUE);
        SDL_RenderClear(app->renderer);

        if (app->keys[SDLK_a])
        { cat->rect.x -= 0.1f; }
        if (app->keys[SDLK_d])
        { cat->rect.x += 0.1f;; }
        if (app->keys[SDLK_w])
        { cat->rect.y -= 0.1f; }
        if (app->keys[SDLK_s])
        { cat->rect.y += 0.1f; }

        r_DrawLabel(50, 50, font, "Oh hell yeah!", app->renderer, GREEN);
        r_DrawImage(app->renderer, cat);

        SDL_RenderPresent( app->renderer ); // Flips our double buffer
    }


    return 0;
}
