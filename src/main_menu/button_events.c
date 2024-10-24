#include "button_events.h"

#include "../application.h"

void start() { application.current_context += 1; }

void quit() { application.is_running = false; }
