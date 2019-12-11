#include <stdio.h>
#include "OS.h"

void process_func(T_process *context)
{
    printf("%-8s\n", context->name);
}

int main(void)
{
    os_init();
    T_process *process1 = process_create(
        (const uint8_t *)"TOTO",
        process_func,
        NULL);
    if (!process1)
        return 1;
    T_process *process2 = process_create(
        (const uint8_t *)"TITI",
        process_func,
        NULL);
    if (!process2)
        return 1;
    os_start_process(process1);
    os_start_process(process2);
    os_infinite_loop();
    return 0;
}
