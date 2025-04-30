#include "main_menu.h"

#include "../application.h"
#include "../log.h"
#include "../ui/uibutton.h"
#include "../ui/uitext.h"

MainMenu* InitMainMenu()
{
    LOG_DEBUG("Init main menu");
    MainMenu* menu = malloc(sizeof(*menu));

    menu->ui_list = CreateElementList(0);

    UIText* title = CreateUIText(20, 20, "Battle Cats!",
                                 application.fonts[LARGE_FONT], WHITE);

    GenericUIElement title_generic = {"title", NULL, NULL, title, TEXT};

    UIButton* play_button = CreateUIButton((SCREEN_WIDTH / 2) - 200, 100, 400,
                                           100, "Play", GRAY, WHITE);

    GenericUIElement play_generic = {"playbtn", NULL, NULL, play_button,
                                     BUTTON};

    AddUIElement(&menu->ui_list, title_generic);

    AddUIElement(&menu->ui_list, play_generic);

    return menu;
}

void RenderMainMenu(MainMenu* menu) { RenderUIElementList(&menu->ui_list); }
