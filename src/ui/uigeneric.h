#ifndef UIGENERIC_H_
#define UIGENERIC_H_

#include "../application.h"
#include "../utils/util.h"
#include "../utils/vec2.h"
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
// UI Update can be any function to define a UI elements behavior
typedef void (*UIUpdateFunc)(SDL_Renderer*, GenericUIElement*);

struct GenericUIElement
{
    char name[33]; // Leaving room for null terminator
    UIRenderFunc render;
    UIUpdateFunc update;
    void* ui_element;
    ElementType element_type;
};

void SetGenericElementPosition(GenericUIElement* ui_element, Vec2 new_position);

void SetRenderFunc(GenericUIElement* ui_element);

void CleanUpGenericElement(GenericUIElement* ui_element);

#endif
