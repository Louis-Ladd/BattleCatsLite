#include "button_events.h"
#include "../application/application.h"

void start(Application* app)
{
    app->current_context += 1;
}

void quit(Application* app)
{
    app->is_running = false;
}
