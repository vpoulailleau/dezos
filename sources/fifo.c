#include "fifo.h"

/* FIXME attention aux deadlocks, pas de gestion de timeout */

void fifo_init(T_fifo *p_fifo)
{
    unsigned char i;
    p_fifo->read = 0;
    p_fifo->write = 0;
    p_fifo->empty = 1;
    for (i = 0; i < FIFO_SIZE; i++)
        p_fifo->data[i] = 0;
}

unsigned char fifo_is_empty(T_fifo *p_fifo)
{
    return p_fifo->empty;
}

unsigned char fifo_is_full(T_fifo *p_fifo)
{
    return (
        (p_fifo->write == p_fifo->read) && (p_fifo->empty == 0));
}

void fifo_write(T_fifo *p_fifo, unsigned char write_data)
{
    while (fifo_is_full(p_fifo))
        ;

    p_fifo->data[p_fifo->write] = write_data;
    p_fifo->write++;
    if (p_fifo->write >= FIFO_SIZE)
        p_fifo->write = 0;
    p_fifo->empty = 0;
}

unsigned char fifo_read(T_fifo *p_fifo)
{
    while (fifo_is_empty(p_fifo))
        ;

    unsigned char return_value = p_fifo->data[p_fifo->read];
    p_fifo->read++;
    if (p_fifo->read >= FIFO_SIZE)
        p_fifo->read = 0;
    if (p_fifo->read == p_fifo->write)
        p_fifo->empty = 1;
    return return_value;
}
