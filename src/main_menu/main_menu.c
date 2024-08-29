#include "main_menu.h"

MainMenu* InitMainMenu(Application* App)
{
    MainMenu* menu = malloc(sizeof(MainMenu));

    menu->buttons[0] = CreateButton(App, (SCREEN_WIDTH /2) - 200, 100, 400, 150, "Button :D", GRAY, WHITE);
    menu->buttons[1] = CreateButton(App, (SCREEN_WIDTH /2) - 200, 260, 400, 150, "Another Button!", GRAY, WHITE);


    return menu;
}

void RenderMainMenu(Application* app, MainMenu* menu)
{
    // Render Buttons
    for (int i = 0; i < MAX_BUTTON_COUNT; i++)
    {
        if (!menu->buttons[i])
        { continue; }

        r_RenderButton(app->renderer, menu->buttons[i]);
    } 
}