#ifndef _OS_H_
#define _OS_H_

#include <stdint.h>
#include "process.h"

#define NB_PROCESSES (4)
#define NB_PRIORITIES (64)

#ifndef NULL
#define NULL ((void *)0)
#endif

#if (NB_PRIORITIES > 255)
#error max is 255
#endif

void os_init(void);
void os_sleep(uint32_t time);
void os_infinite_loop(void);
void os_start_process(T_process *process);

#endif /* _OS_H_ */
