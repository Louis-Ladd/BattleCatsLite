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

void ResizeElements(GenericUIElementList* list, u32 new_size);

// void AddUIElement(GenericUIElement* element) {}

#endif
