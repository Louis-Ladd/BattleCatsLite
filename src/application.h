#ifndef APPLICATION_H_
#define APPLICATION_H_

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#include "scene/scene_manager.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

enum FontEnum
{
    SMALL_FONT,
    MEDIUM_FONT,
    LARGE_FONT,
    XLARGE_FONT
};

enum ContextEnum
{
    MAIN_MENU,
    LEVEL_ONE,
    LEVEL_TWO
};

typedef struct
{
	bool ShowHealthBar;
	bool ShowBoundingBoxes;
} GlobalGameSettings;

struct Application
{
    SDL_Window* window;
    SDL_Surface* window_surface;
    SDL_Renderer* renderer;
    SceneManager* scene_manager;
    SDL_Event window_event;
    bool is_running;
    bool keys[322];
    TTF_Font* fonts[4];
    double fps;
    float delta_time;
    int current_context;
    int timer;
	GlobalGameSettings game_state;
};

int InitApplication(struct Application* application);

extern struct Application application;

#endif
