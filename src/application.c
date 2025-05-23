#include "application.h"
#include "log.h"
#include <SDL2/SDL_render.h>

int InitApplication(struct Application* application)
{
    LOG("Starting application...");

    for (int i = 0; i < 322; i++)
    {
        application->keys[i] = false;
    }

    application->is_running = true;

    LOG_DEBUG("Starting SDL");
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "Failed to initialize the SDL2 library\n");
        return 1;
    }

    LOG_DEBUG("Starting SDL_TTF");
    if (TTF_Init() < 0)
    {
        fprintf(stderr, "Failed to initialize fonts\n");
        return 2;
    }

    LOG_DEBUG("Loading fonts");
    application->fonts[SMALL_FONT] = TTF_OpenFont("assets/noodle.ttf", 16);
    application->fonts[MEDIUM_FONT] = TTF_OpenFont("assets/noodle.ttf", 32);
    application->fonts[LARGE_FONT] = TTF_OpenFont("assets/noodle.ttf", 64);
    application->fonts[XLARGE_FONT] = TTF_OpenFont("assets/noodle.ttf", 128);

    if (!application->fonts[SMALL_FONT])
    {
        fprintf(stderr, "Failed to load fonts (make sure assets directory is "
                        "accessable!)\n");
        return 2;
    }

    LOG_DEBUG("Loading SDL_Image");
    if (IMG_Init(IMG_INIT_PNG) < 0)
    {
        fprintf(stderr, "Failed ot initialize SDL2 Image library\n");
        return 3;
    }

    LOG_DEBUG("Creating window");
    application->window = SDL_CreateWindow(
        "Battle Cats!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    if (!application->window)
    {
        fprintf(stderr, "Failed to create window\n");
        return 4;
    }

    SDL_SetWindowResizable(application->window, SDL_FALSE);

    LOG_DEBUG("Creating renderer");
    application->renderer =
        SDL_CreateRenderer(application->window, -1, SDL_RENDERER_ACCELERATED);

    if (!application->renderer)
    {
        fprintf(stderr, "Failed to create renderer\n");
        return 5;
    }

    application->delta_time = 0.f;
    application->timer = 0;

    application->current_context = MAIN_MENU;

    return 0;
}
