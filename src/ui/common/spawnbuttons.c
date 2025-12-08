#include "spawnbuttons.h"

#define BUTTON_HEIGHT 50
#define BUTTON_WIDTH 150 
#define SPACING 200 

UIButton* _create_button(int x, int y)
{
	return CreateUIButton(x, y, BUTTON_WIDTH, BUTTON_HEIGHT, "TEST", ORANGE, WHITE);
}

void create_spawn_buttons(GenericUIElementList* list, int x_offset, int y_offset, int columns, int rows)
{
	for (int c = 0; c < columns; c++)
	{
		for (int r = 0; r < rows; r++)
		{
			GenericUIElement button = {"TEST", NULL, NULL, _create_button(x_offset+(c*BUTTON_WIDTH*1.5), y_offset+(r*BUTTON_HEIGHT*1.5)), BUTTON};
			AddUIElement(list, button);
		}
	}
}
