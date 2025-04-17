#include "uigeneric.h"
#include "uirender.h"

void SetRenderFunc(GenericUIElement* ui_element)
{
    switch (ui_element->element_type)
    {
        case BUTTON:
            ui_element->render = ui_RenderButton;
            break;
        default:
            ui_element->render = NULL;
            break;
    }
}
