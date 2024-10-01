#include "main_menu.h"

MainMenu* InitMainMenu(Application* app)
{
    MainMenu* menu = malloc(sizeof(*menu));

    for (int i = 0; i < MAX_BUTTON_COUNT; i++)
    {
        menu->buttons[i] = NULL;
    }

    menu->buttons[0] = CreateButton(app, (SCREEN_WIDTH /2) - 200, 100, 400, 150, "Button :D", GRAY, WHITE);
    SetButtonFuncPointer(menu->buttons[0], &start);
    menu->buttons[1] = CreateButton(app, (SCREEN_WIDTH /2) - 200, 260, 400, 150, "Quit", GRAY, WHITE);
    SetButtonFuncPointer(menu->buttons[1], &quit);

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
