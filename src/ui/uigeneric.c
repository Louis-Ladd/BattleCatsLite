#include "uigeneric.h"
#include "../log.h"
#include "uibutton.h"
#include "uiimage.h"
#include "uirender.h"
#include "uitext.h"

void SetGenericElementPosition(GenericUIElement* ui_element, Vec2 new_position)
{
	switch (ui_element->element_type)
	{
		case TEXT:
			SetUITextPosition((UIText*)ui_element->ui_element, new_position);
			break;
		case IMAGE:
			break;
		case BUTTON:
			break;
		case ICON_BUTTON:
			// TODO: implement
			LOG_WARN("Icon button cleanup not implemented!");
			break;
		default:
			LOG_ERROR("Unkown UI type passed into cleanup!");
			break;
	}
}

void SetRenderFunc(GenericUIElement* ui_element)
{
	switch (ui_element->element_type)
	{
		case BUTTON:
			ui_element->render = ui_RenderButton;
			break;
		case TEXT:
			ui_element->render = ui_RenderText;
			LOG_DEBUG("Set ui_element of type TEXT");
			break;
		default:
			ui_element->render = NULL;
			break;
	}
}

void CleanUpGenericElement(GenericUIElement* ui_element)
{
	if (ui_element == NULL)
	{
		LOG_ERROR("Null element passed!");
		return;
	}
	switch (ui_element->element_type)
	{
		case TEXT:
			DestroyUIText((UIText*)ui_element->ui_element);
			break;
		case IMAGE:
			DestroyUIImage((UIImage*)ui_element->ui_element);
			break;
		case BUTTON:
			DestroyUIButton((UIButton*)ui_element->ui_element);
			break;
		case ICON_BUTTON:
			// TODO: implement
			LOG_WARN("Icon button cleanup not implemented!");
			break;
		default:
			LOG_ERROR("Unkown UI type passed into cleanup!");
			break;
	}

	free(ui_element);
}
