#include "OS.h"
#include "list.h"

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
        if (ready.start == NULL) /* empty list */
            break;               /* TODO break if no more processes, not only not ready processes */
        T_element *elem = list_pop_first(&ready);
        T_process *process = (T_process *)elem->data;
        uint8_t ret_val = process->entry_point(process);
        if (ret_val == _COROUTINE_INTERRUPTED)
        {
            list_append(&ready, elem);
        }
        else
        { /* TODO dealloction, kill process */
        }
    }
    while (1)
    {
        /* nothing left to be done */
    }
}

void os_start_process(T_process *process)
{
    T_element *elem = list_create_element(process);
    list_append(&ready, elem);
}
