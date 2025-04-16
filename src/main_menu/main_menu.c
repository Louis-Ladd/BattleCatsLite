#include "main_menu.h"

#include "../application.h"
#include "../log.h"

MainMenu* InitMainMenu()
{
    LOG_DEBUG("Init main menu");
    MainMenu* menu = malloc(sizeof(*menu));

    // TODO: Implement proper generics for UI

    return menu;
}

void RenderMainMenu(MainMenu* menu)
{
    LOG("Not implemented %i", menu->ui_list.element_count);
}
