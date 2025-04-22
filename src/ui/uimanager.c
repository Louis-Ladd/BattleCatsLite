#include "uimanager.h"
#include "../application.h"
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

    LOG_DEBUG("Created new element list...");

    return new_list;
}

void RenderUIElementList(GenericUIElementList* list)
{
    for (u32 i = 0; i < list->element_count; i++)
    {
        if (list->elements[i] == NULL)
        {
            break;
        }
        list->elements[i]->render(application.renderer, list->elements[i]);
    }
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

    LOG_DEBUG("Resizing elements to... %ld bytes or %i elements",
              sizeof(*list->elements) * new_size, new_size);

    GenericUIElement** new_elements =
        realloc(list->elements, sizeof(*list->elements) * new_size);

    if (!new_elements)
    {
        LOG_ERROR("Mother fuck, realloc failed");
        return;
    }

    list->elements = new_elements;

    list->element_count = new_size;
}

void AddUIElement(GenericUIElementList* list, GenericUIElement element)
{
    GenericUIElement* alloc_element = malloc(sizeof(*alloc_element));

    *alloc_element = element;

    SetRenderFunc(alloc_element);

    ResizeElements(list, list->element_count + 1);

    list->elements[list->element_count - 1] = alloc_element;
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
    // TODO: This is hack for now, but these removals will cause issues since we
    // don't reorganize the pointer array to remove the NULL gaps.
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
