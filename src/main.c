#include "main.h"

struct Application* app;

int main()
{
    app = InitApplication();

    if (!app)
    {
        printf("Application failed to initalize");
        return 1;
    }

    TTF_Font* font;
    struct Image* sprite_sheet;

    sprite_sheet = r_CreateImage(app->renderer, IMG_Load("assets/catspritesheet.png"), 0, 0, 2560, 2560);

    font = TTF_OpenFont("assets/noodle.ttf", 125);

    SDL_RenderPresent(app->renderer);

    struct Sprite* cat = r_CreateSprite(CAT, 50, 50, 0.2f);

    struct Label* battle_cats = r_CreateLabel(app->renderer, 50, 50, "Battle Cats!", font, ORANGE);

    long long time_since_last_call = current_timestamp();
    long long time_now = current_timestamp();

    const float speed = 80.f;
    while(app->is_running)
    {
        time_now = current_timestamp();
        app->delta_time = (float)((time_now - time_since_last_call)) / 1000;
        time_since_last_call = time_now;

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
        { cat->f_rect.x -= speed*app->delta_time; }
        if (app->keys[SDLK_d])
        { cat->f_rect.x += speed*app->delta_time; }
        if (app->keys[SDLK_w])
        { cat->f_rect.y -= speed*app->delta_time; }
        if (app->keys[SDLK_s])
        { cat->f_rect.y += speed*app->delta_time; }


        r_DrawSprite(app->renderer, sprite_sheet, cat);

        r_DrawLabel(app->renderer, battle_cats);

        if (battle_cats->rect.x < SCREEN_WIDTH)
        {
            battle_cats->rect.x += 100*app->delta_time;
        }
        else 
        {
            battle_cats->rect.x = 0 - battle_cats->rect.w;
        }

        SDL_RenderPresent( app->renderer ); // Flips our double buffer
    }

    return 0;
}
