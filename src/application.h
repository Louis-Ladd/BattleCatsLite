#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "scene/scene_manager.h"
#include "ui/uimanager.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
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
	struct 
	{
		bool show_health_bar;
		bool show_bounding_boxes;
	} debug;
	struct
	{
		int screen_width;
		int screen_height;
	} window;
} GlobalGameSettings;

struct Application
{
	SDL_Window* window;
	SDL_Surface* window_surface;
	SDL_Renderer* renderer;
	SceneManager* scene_manager;
	SDL_Event window_event;
	GlobalGameSettings game_state;
	GenericUIElementList* m_current_ui_list;
	bool is_running;
	bool keys[322];
	TTF_Font* fonts[4];
	double fps;
	float delta_time;
	int current_context;
	int timer;
};

int GetScreenHeight();

int GetScreenWidth();

int InitApplication(struct Application* application);

int SetGlobalUIList(GenericUIElementList* new_ui_list);

GenericUIElementList* GetGlobalUIList();

int ReleaseGlobalUIList();

extern struct Application application;

#endif
