#include <stdio.h>
#include "OS.h"

uint8_t process_func(T_process *context)
{
    printf("%-8s\n", context->name);
    return 0;
}

int main(void)
{
    os_init();

    T_process *process1 = process_create(
        (const uint8_t *)"PROC FOO",
        process_func,
        NULL);
    if (!process1)
        return 1;
    os_start_process(process1);

    T_process *process2 = process_create(
        (const uint8_t *)"PROC BAR",
        process_func,
        NULL);
    if (!process2)
        return 1;
    os_start_process(process2);

    os_infinite_loop();

    return 0;
}
