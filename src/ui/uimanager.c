#include "uimanager.h"
#include "../log.h"
#include "uigeneric.h"
#include <stdlib.h>
#include <string.h>

GenericUIElementList CreateElementList(u32 start_count)
{
    GenericUIElementList new_list;
    new_list.element_count = start_count;

    new_list.elements = malloc(sizeof(**new_list.elements) * start_count);

    memset(new_list.elements, 0, sizeof(*new_list.elements) * start_count);

    return new_list;
}

void ResizeElements(GenericUIElementList* list, u32 new_size)
{
    if (new_size < list->element_count)
    {
        while (list->element_count > new_size)
        {
            free(list->elements[list->element_count]);
            list->element_count--;
        }
    }

    list->elements =
        realloc(list->elements,
                sizeof(**list->elements) * (new_size - list->element_count));
}

void AddUIElement(GenericUIElementList* list, GenericUIElement* element)
{
    ResizeElements(list, list->element_count + 1);

    list->elements[list->element_count + 1] = element;
}
GenericUIElement* GetUIElementByName(GenericUIElementList* list,
                                     char element_name[])
{
    GenericUIElement* found_element = NULL;

    for (u32 i = 0; i < list->element_count; i++)
    {
        if (strcmp(list->elements[i]->name, element_name) == 0)
        {
            found_element = list->elements[i];
            list->elements[i] = NULL;
        }
    }

    return found_element;
}

void RemoveUIElementByPointer(GenericUIElementList* list,
                              GenericUIElement* element)
{
    GenericUIElement* found_element = NULL;

    for (u32 i = 0; i < list->element_count; i++)
    {
        if (element == list->elements[i])
        {
            found_element = list->elements[i];
            list->elements[i] = NULL;
        }
    }

    if (found_element == NULL)
    {
        LOG_WARN("Unable to find element by pointer: %p", element);
        return;
    }

    CleanUpGenericElement(element);
}

void RemoveUIElementByName(GenericUIElementList* list, char element_name[])
{
    GenericUIElement* found_element = GetUIElementByName(list, element_name);

    if (found_element == NULL)
    {
        LOG_WARN("Unable to find element by name: %s", element_name);
        return;
    }

    CleanUpGenericElement(found_element);
}
