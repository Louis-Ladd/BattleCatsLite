#include "uirender.h"
#include "button.h"
#include "text.h"
#include "uigeneric.h"

void ui_RenderText(SDL_Renderer* renderer, GenericUIElement* element)
{
    r_RenderText(renderer, (Text*)element->ui_element);
}

void ui_RenderButton(SDL_Renderer* renderer, GenericUIElement* element)
{
    r_RenderButton(renderer, (Button*)element->ui_element);
}
