#ifndef MAIN_MENU_H_
#define MAIN_MENU_H_

#define MAX_BUTTON_COUNT 3

#include "button_events.h"
#include "../ui/button.h"

typedef struct {
    Button* buttons[MAX_BUTTON_COUNT]; 
// Other elements like images, text, etc
} MainMenu;

MainMenu* InitMainMenu(Application* App); 

void RenderMainMenu(Application* app, MainMenu* menu);

void DestroyMainMenu(MainMenu* menu); 

#endif
