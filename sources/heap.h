#ifndef HEAP_H
#define HEAP_H

#include <stdint.h>

#define NULL ((void *)0)

void heap_init(void);
void *heap_malloc(uint16_t size);
void heap_free(void *user_memory, uint16_t size);

#endif