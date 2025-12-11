#include "button_events.h"
#include "../levels/level.h"

#include "../application.h"

void mainmenustart()
{
	application.current_context = 1;

	ReleaseGlobalUIList();
	create_level_one(application.scene_manager);

	return;
}

void quit() { application.is_running = false; }
