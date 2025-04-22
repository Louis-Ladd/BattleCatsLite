#include "uirender.h"
#include "uibutton.h"
#include "uigeneric.h"
#include "uitext.h"

void ui_RenderText(SDL_Renderer* renderer, GenericUIElement* element)
{
    r_RenderUIText(renderer, (UIText*)element->ui_element);
}

void ui_RenderButton(SDL_Renderer* renderer, GenericUIElement* element)
{
    r_RenderUIButton(renderer, (UIButton*)element->ui_element);
}
