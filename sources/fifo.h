#ifndef FIFO_H
#define FIFO_H

#include <stdint.h>

#define FIFO_SIZE (128)

typedef struct
{
    uint8_t data[FIFO_SIZE];
    volatile uint8_t write;
    volatile uint8_t read;
    volatile uint8_t empty;
} T_fifo;

void fifo_init(T_fifo *p_fifo);
uint8_t fifo_is_empty(T_fifo *p_fifo);
uint8_t fifo_is_full(T_fifo *p_fifo);
void fifo_write(T_fifo *p_fifo, uint8_t write_data);
uint8_t fifo_read(T_fifo *p_fifo);

#endif /* FIFO_H */