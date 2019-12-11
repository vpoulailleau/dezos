#include "process.h"
#include "heap.h"

T_process *process_create(
    const unsigned char *name,
    const process_entry_point_t entry_point,
    void *const user_context)
{
    unsigned char i;
    T_process *process;

    process = (T_process *)heap_malloc(sizeof(T_process));
    if (!process)
        return NULL;

    /* strncpy */
    for (i = 0; i < PROCESS_NAME_LENGTH; i++)
    {
        process->name[i] = name[i];
    }

    process->priority = 0;
    process->entry_point = entry_point;
    process->execution_time = 0;
    process->timer = 0;
    process->user_context = user_context;

    return process;
}

void process_destroy(T_process *process)
{
    heap_free(process, sizeof(T_process));
}