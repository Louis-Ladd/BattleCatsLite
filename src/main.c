#include "main.h"
#include "application.h"
#include "log.h"
#include "main_menu/main_menu.h"
#include "render/label.h"
#include "ui/uimanager.h"
#include "utils/current_time.h"
#include "utils/types.h"
#include <SDL2/SDL_timer.h>
#include <stdio.h>

MainMenu* main_menu;

struct Application application;

int main()
{
    int application_status = InitApplication(&application);

    if (application_status > 0)
    {
        LOG_ERROR("init failed!!! :(");
        fprintf(stderr, "Application failed to initalize\n");
        return application_status;
    }

    main_menu = InitMainMenu();
    application.scene_manager = InitSceneManager();

    u64 fps_count = 0;
    u64 last_time = SDL_GetTicks();
    u64 fps_start_time = SDL_GetTicks();

    LOG("Game Starting...");

    char fps_string[50] = "FPS: ";

    while (application.is_running)
    {
        u64 current_time = SDL_GetTicks();
        application.delta_time = (current_time - last_time) / 1000.0f;
        last_time = current_time;

        handle_events();

        SDL_RenderClear(application.renderer);

        main_update();
        // main_render();
        RenderMainMenu(main_menu);

        snprintf(fps_string, sizeof(fps_string), "FPS: %.2f",
                 application.fps == INFINITY ? 1000 : application.fps);

        r_DrawText(20, 20, application.fonts[MEDIUM_FONT], fps_string,
                   application.renderer, GREEN);

        SDL_RenderPresent(application.renderer); // Flips our double buffer

        application.timer++;
        fps_count++;
        if (current_time - fps_start_time >= 1000)
        {
            application.fps = fps_count / (application.delta_time);
            fps_count = 0;
        }
    }

    return 0;
}

void main_render()
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

void main_update()
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

inline void handle_events()
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
            case SDL_KEYDOWN ... SDL_KEYUP: // This syntax is
                                            // radical
                HandleKeyboardInput();
                break;
            case SDL_MOUSEBUTTONDOWN ... SDL_MOUSEBUTTONUP:
                switch (application.current_context)
                {
                    case MAIN_MENU:
                        break;
                }
                break;
        }
    }
}
