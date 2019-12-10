#ifndef HEAP_H
#define HEAP_H

#define NULL ((void *)0)

void heap_init(void);
void *heap_malloc(unsigned short size);
void heap_free(void *user_memory, unsigned short size);

#endif