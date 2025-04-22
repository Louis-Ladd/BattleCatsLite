#ifndef UIMANAGER_H_
#define UIMANAGER_H_

#include "../utils/types.h"
#include "./uigeneric.h"

typedef struct
{
    u32 element_count;
    GenericUIElement** elements;
} GenericUIElementList;

GenericUIElementList CreateElementList(u32 start_count);

void RenderUIElementList(GenericUIElementList* list);

void ResizeElements(GenericUIElementList* list, u32 new_size);

void AddUIElement(GenericUIElementList* list, GenericUIElement element);

GenericUIElement* GetUIElementByName(GenericUIElementList* list,
                                     char element_name[]);

void RemoveUIElementByPointer(GenericUIElementList* list,
                              GenericUIElement* element);

void RemoveUIElementByName(GenericUIElementList* list, char element_name[]);

#endif
