#include "main.h"

Application* app;
MainMenu* main_menu;

int main()
{
    app = InitApplication();

    if (!app)
    {
        printf("Application failed to initalize");
        return 1;
    }

    main_menu = InitMainMenu(app); 

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
    switch (app->current_context)
    {
        case MAIN_MENU:
            RenderMainMenu(app, main_menu);
            break;
        case LEVEL_ONE:
            break;
    }
}

void update()
{
} 

void handle_events()
{
    while(SDL_PollEvent(&app->window_event) > 0)
    {
        //TODO: Pull this out into it's own file and organize it better.
        //      Two levels of switch cases is not optimal.
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
            case SDL_MOUSEBUTTONDOWN:
                switch (app->current_context)
                {
                    case MAIN_MENU:
                        HandleMouseInputMainMenu(app, main_menu);
                        break;
                }
                break;
        }
    }
}