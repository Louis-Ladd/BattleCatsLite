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

    int fps_count = 0;
    long long fps_timer = current_timestamp();

    long long time_since_last_call = current_timestamp();
    long long time_now = current_timestamp();

    while(app->is_running)
    {
        time_now = current_timestamp();
        app->delta_time = (float)((time_now - time_since_last_call)) / 1000;
        time_since_last_call = time_now;

        handle_events();

        SDL_SetRenderDraw_SDL_Color(app->renderer, DARK_BLUE);
        SDL_RenderClear(app->renderer);

        update();
        render();

        SDL_RenderPresent( app->renderer ); // Flips our double buffer

        app->timer ++;
        fps_count ++;
        if (((float)(current_timestamp()- fps_timer))/1000.f >= 1)
        {
            app->fps = fps_count;
            fps_count = 0;
            fps_timer = current_timestamp();
        }
    }

    return 0;
}

void render()
{
    r_DrawText(10, 10, app->fonts[SMALL_FONT], "Small Font", app->renderer, GREEN);
    r_DrawText(10, 26, app->fonts[MEDIUM_FONT], "Medium Font", app->renderer, GREEN);
    r_DrawText(10, 58, app->fonts[LARGE_FONT], "Large Font", app->renderer, GREEN);
    r_DrawText(10, 128, app->fonts[XLARGE_FONT], "Extra Large Font", app->renderer, GREEN);
}

void update()
{
    printf("FPS: %i\n", app->fps);
} 

void handle_events()
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
}