#include <stdio.h>
#include "OS.h"

void toto_func(void)
{
    printf("TOTO\n");
    os_sleep(500);
    printf("TOTO\n");
    os_sleep(500);
    printf("TOTO\n");
}

void titi_func(void)
{
    printf("TITI\n");
    os_sleep(500);
    printf("TITI\n");
    os_sleep(500);
    printf("TITI\n");
}

int main(void)
{
    os_init();
    T_process *process1 = process_create((const uint8_t *)"TOTO", toto_func);
    if (!process1)
        return 1;
    T_process *process2 = process_create((const uint8_t *)"TITI", titi_func);
    if (!process2)
        return 1;
    os_start_process(process1);
    os_start_process(process2);
    os_infinite_loop();
    return 0;
}
