#ifndef LIST_H
#define LIST_H

#include <stdint.h>

typedef struct _element
{
    void *data;
    struct _element *next;
    struct _element *previous;
} T_element;

typedef struct
{
    T_element *start;
    T_element *end;
} T_list;

typedef void (*T_function)(void *data);

T_element *list_create_element(void *data);
uint32_t list_length(T_list *list);
void list_append(T_list *list, T_element *element);
void list_prepend(T_list *list, T_element *element);
void list_insert_at(T_list *list, T_element *element, uint32_t index);
T_element *list_pop_first(T_list *list);
T_element *list_pop_last(T_list *list);
T_element *list_pop_at(T_list *list, uint32_t index);
void list_map(T_list *list, T_function function);

#endif