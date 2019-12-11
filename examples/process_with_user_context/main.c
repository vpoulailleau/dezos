#include <stdio.h>
#include <stdint.h>
#include "OS.h"

typedef struct
{
    uint32_t execution_count;
} T_user_context;

void process_func(T_process *context)
{
    T_user_context *user_context = (T_user_context *)context->user_context;
    printf(
        "%-8s was called %d times\n",
        context->name,
        user_context->execution_count);
    user_context->execution_count++;
}

int main(void)
{
    os_init();

    T_user_context process1_context = {.execution_count = 0};
    T_process *process1 = process_create(
        (const uint8_t *)"TOTO",
        process_func,
        &process1_context);
    if (!process1)
        return 1;

    T_user_context process2_context = {.execution_count = 1000};
    T_process *process2 = process_create(
        (const uint8_t *)"TITI",
        process_func,
        &process2_context);
    if (!process2)
        return 1;

    os_start_process(process1);
    os_start_process(process2);
    os_infinite_loop();
    return 0;
}
