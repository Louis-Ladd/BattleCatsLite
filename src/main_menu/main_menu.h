#ifndef MAIN_MENU_H_
#define MAIN_MENU_H_

#define MAX_BUTTON_COUNT 3

#include "../ui/button.h"

typedef struct {
    Button* buttons[MAX_BUTTON_COUNT]; 
// Other elements like images, text, etc
} MainMenu;

void InitMainMenu(SDL_Renderer* renderer, MainMenu *menu); 

void RenderMainMenu(Application* app);

#endif
