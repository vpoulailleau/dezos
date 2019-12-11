#include "OS.h"
#include "list.h"

static T_process *running_process = NULL;
static T_list ready;
static T_list stopped;
static T_list waiting;
static T_list processes_by_prio[NB_PRIORITIES];

void os_init(void)
{
    unsigned char i;
    T_list empty_list = {.start = NULL, .end = NULL};

    ready = empty_list;
    stopped = empty_list;
    waiting = empty_list;

    for (i = 0; i < NB_PRIORITIES; i++)
    {
        processes_by_prio[i] = empty_list;
    }
}

void os_sleep(uint32_t time)
{
    uint32_t i;
    for (i = 0; i < time; i++)
        ;
}

void os_infinite_loop()
{
    while (1)
    {
        /* TODO manage empty list */
        T_element *elem = list_pop_first(&ready);
        T_process *process = (T_process *)elem->data;
        process->entry_point(process);
        list_append(&ready, elem);
    }
}

void os_start_process(T_process *process)
{
    T_element *elem = list_create_element(process);
    list_append(&ready, elem);
}
