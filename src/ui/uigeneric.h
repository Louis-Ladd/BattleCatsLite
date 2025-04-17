#ifndef UIGENERIC_H_
#define UIGENERIC_H_

#include "../application.h"
#include "../utils/util.h"
#include <SDL2/SDL_render.h>

typedef enum
{
    TEXT,
    IMAGE,
    BUTTON,
    ICON_BUTTON
} ElementType;

typedef struct GenericUIElement GenericUIElement;
typedef void (*UIRenderFunc)(SDL_Renderer*, GenericUIElement*);

struct GenericUIElement
{
    UIRenderFunc render;
    void* ui_element;
    ElementType element_type;
};

void SetRenderFunc(GenericUIElement* ui_element);

#endif
