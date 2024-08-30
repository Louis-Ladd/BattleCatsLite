#include "button_events.h"

void start(Application* app)
{
    app->current_context = LEVEL_ONE;
}

void quit(Application* app)
{
    app->is_running = false;
}