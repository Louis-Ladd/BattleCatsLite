#ifndef MAIN_MENU_H_
#define MAIN_MENU_H_

#define MAX_BUTTON_COUNT 3

#include "../ui/uibutton.h"
#include "../ui/uigeneric.h"
#include "../ui/uimanager.h"
#include "button_events.h"

typedef struct
{
	GenericUIElementList ui_list;
} MainMenu;

MainMenu* InitMainMenu();

void RenderMainMenu(MainMenu* menu);

void DestroyMainMenu(MainMenu* menu);

#endif
