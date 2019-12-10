#ifndef FIFO_H
#define FIFO_H

#define FIFO_SIZE (128)

typedef struct
{
    unsigned char data[FIFO_SIZE];
    volatile unsigned char write;
    volatile unsigned char read;
    volatile unsigned char empty;
} T_fifo;

void fifo_init(T_fifo *p_fifo);
unsigned char fifo_is_empty(T_fifo *p_fifo);
unsigned char fifo_is_full(T_fifo *p_fifo);
void fifo_write(T_fifo *p_fifo, unsigned char write_data);
unsigned char fifo_read(T_fifo *p_fifo);

#endif /* FIFO_H */