#include "uimanager.h"
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
