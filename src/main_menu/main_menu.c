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

	SetGlobalUIList(&menu->ui_list);

	UIText* title = CreateUIText(0, 0, "Battle Cats!",
								 application.fonts[LARGE_FONT], WHITE);
	Vec2 title_position = {
		((float)GetScreenWidth() / 2) - (title->label->f_rect.w / 2), 100};

	SetUITextPosition(title, title_position);

	GenericUIElement title_generic = {"title", NULL, NULL, title, TEXT};

	UIButton* play_button = CreateUIButton(((float)GetScreenWidth() / 2) - 200, 300,
										   400, 100, "Play", GRAY, WHITE);

	SetUIButtonFuncPointer(play_button, mainmenustart);

	GenericUIElement play_generic = {"playbtn", NULL, NULL, play_button,
									 BUTTON};

	AddUIElement(&menu->ui_list, title_generic);

	AddUIElement(&menu->ui_list, play_generic);

	return menu;
}

void RenderMainMenu(MainMenu* menu) { RenderUIElementList(&menu->ui_list); }
