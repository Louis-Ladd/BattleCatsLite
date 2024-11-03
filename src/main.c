#include "main.h"
#include "application.h"
#include "main_menu/main_menu.h"

MainMenu* main_menu;

struct Application application;

int main()
{
    int application_status = InitApplication(&application);

    if (application_status > 0)
    {
        fprintf(stderr, "Application failed to initalize\n");
        return application_status;
    }

    main_menu = InitMainMenu();
    application.scene_manager = InitSceneManager();

    create_level_one(application.scene_manager);

    int fps_count = 0;
    long long fps_timer = current_timestamp();

    long long time_since_last_call = current_timestamp();
    long long time_now = current_timestamp();

    LOG("Application Starting...");

    while (application.is_running)
    {
        time_now = current_timestamp();
        application.delta_time =
            (float)((time_now - time_since_last_call)) / 1000;
        time_since_last_call = time_now;

        handle_events();

        SDL_SetRenderDraw_SDL_Color(application.renderer, DARK_BLUE);
        SDL_RenderClear(application.renderer);

        update();
        render();

        SDL_RenderPresent(application.renderer); // Flips our double buffer

        application.timer++;
        fps_count++;
        if (((float)(current_timestamp() - fps_timer)) / 1000.f >= 1)
        {
            application.fps = fps_count;
            fps_count = 0;
            fps_timer = current_timestamp();
        }
    }

    return 0;
}

void render()
{
    switch (application.current_context)
    {
        case MAIN_MENU:
            RenderMainMenu(main_menu);
            break;
        case LEVEL_ONE:
            RenderScene(application.scene_manager->scenes[0]);
            break;
    }
}

void update()
{
    switch (application.current_context)
    {
        case MAIN_MENU:
            break;
        case LEVEL_ONE:
            UpdateScene(application.scene_manager->scenes[0]);
            break;
    }
}

void handle_events()
{
    while (SDL_PollEvent(&application.window_event) > 0)
    {
        // TODO: Pull this out into it's own file and organize it
        // better.
        //       Two levels of switch cases is not optimal.
        switch (application.window_event.type)
        {
            case SDL_QUIT:
                application.is_running = false;
                break;
            case SDL_KEYDOWN ... SDL_KEYUP: // This syntax is radical
                HandleKeyboardInput();
                break;
            case SDL_MOUSEBUTTONDOWN ... SDL_MOUSEBUTTONUP:
                switch (application.current_context)
                {
                    case MAIN_MENU:
                        HandleMouseInputMainMenu(main_menu);
                        break;
                }
                break;
        }
    }
}
