#include "main_menu.h"

#include "../application.h"
#include "../log.h"
#include "../ui/uitext.h"

MainMenu* InitMainMenu()
{
    LOG_DEBUG("Init main menu");
    MainMenu* menu = malloc(sizeof(*menu));

    menu->ui_list = CreateElementList(0);

    UIText* title = CreateUIText(20, 20, "Battle Cats!",
                                 application.fonts[LARGE_FONT], WHITE);

    GenericUIElement title_generic = {"title", NULL, NULL, title, TEXT};

    AddUIElement(&menu->ui_list, title_generic);

    return menu;
}

void RenderMainMenu(MainMenu* menu) { RenderUIElementList(&menu->ui_list); }
