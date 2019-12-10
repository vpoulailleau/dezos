#include "list.h"
#include "heap.h"

T_element *list_create_element(void *data)
{
    T_element *element = heap_malloc(sizeof(T_element));
    if (element != NULL)
    {
        element->data = data;
        element->next = NULL;
        element->previous = NULL;
    }
    return element;
}

unsigned long list_length(T_list *list)
{
    unsigned long length = 0;
    T_element *p;

    p = list->start;
    while (p)
    {
        p = p->next;
        length++;
    }
    return length;
}

void list_append(T_list *list, T_element *element)
{
    element->previous = list->end;
    if (list->end)
        list->end->next = element;
    list->end = element;
    if (list->start == NULL)
        list->start = element;
}

void list_prepend(T_list *list, T_element *element)
{
    element->next = list->start;
    if (list->start)
        list->start->previous = element;
    list->start = element;
    if (list->end == NULL)
        list->end = element;
}

T_element *list_pop_first(T_list *list)
{
    if (list->start != NULL)
    {
        T_element *popped = list->start;
        if (popped->next)
            popped->next->previous = NULL;
        list->start = popped->next;
        popped->next = NULL;
        return popped;
    }
    return NULL;
}

T_element *list_pop_last(T_list *list)
{
    if (list->end != NULL)
    {
        T_element *popped = list->end;
        if (popped->previous)
            popped->previous->next = NULL;
        list->end = popped->previous;
        popped->previous = NULL;
        return popped;
    }
    return NULL;
}

void list_insert_at(T_list *list, T_element *element, unsigned long index)
{
    if (list->start != NULL)
    {
        unsigned long i = 0;
        T_element *previous_element = list->start;
        while (previous_element->next != NULL && i < index)
        {
            previous_element = previous_element->next;
            i++;
        }
        if (i == index)
        {
            element->next = previous_element->next;
            if (previous_element->next != NULL)
                previous_element->next->previous = element;
            element->previous = previous_element;
            previous_element->next = element;
        }
    }
}

void list_map(T_list *list, T_function function)
{
    T_element *element = list->start;
    while (element != NULL)
    {
        function(element->data);
        element = element->next;
    }
}

T_element *list_pop_at(T_list *list, unsigned long index)
{
    T_element *popped = list->start;
    unsigned long popped_index = 0;

    while ((popped_index != index) && (popped->next != NULL))
    {
        index++;
        popped = popped->next;
    }
    if (popped_index == index)
    {
        if (popped->previous)
        {
            popped->previous->next = popped->next;
            if (popped->next)
                popped->next->previous = popped->previous;
            else
                list->end = popped->previous;
        }
        else
        {
            list->start = popped->next;
            if (popped->next)
                popped->next->previous = NULL;
            else
                list->end = NULL;
        }
        return popped;
    }
    return NULL;
}
