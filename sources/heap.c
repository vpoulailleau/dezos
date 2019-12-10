#include "heap.h"

#define BLOCK_SIZE (16)
#define NB_BLOCKS (1024)

static uint8_t memory[NB_BLOCKS * BLOCK_SIZE];
static uint8_t status[NB_BLOCKS];

#define FREE (0)
#define USED (1)

void heap_init(void)
{
    uint16_t i;
    for (i = 0; i < NB_BLOCKS; i++)
        status[i] = FREE;
    for (i = 0; i < NB_BLOCKS * BLOCK_SIZE; i++)
        memory[i] = 0;
}

void *heap_malloc(uint16_t size)
{
    /* FIXME line 31 may cause problem */
    uint16_t first_free_block;
    uint16_t next_block;
    uint16_t nb_blocks = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
    for (first_free_block = 0; first_free_block < NB_BLOCKS; first_free_block++)
    {
        if (status[first_free_block] == USED)
            continue;
        for (next_block = first_free_block; next_block < first_free_block + nb_blocks; next_block++)
        {
            if (status[next_block] == USED)
            {
                first_free_block = next_block + 1;
                break;
            }
        }
        /* if found correct first block */
        if (next_block == first_free_block + nb_blocks)
        {
            for (next_block = first_free_block; next_block < first_free_block + nb_blocks; next_block++)
                status[next_block] = USED;
            return (void *)(&memory[first_free_block * BLOCK_SIZE]);
        }
    }
    return NULL;
}

void heap_free(void *user_memory, uint16_t size)
{
    uint16_t nb_blocks = (size + BLOCK_SIZE - 1) / BLOCK_SIZE;
    uint16_t first_block = (uint8_t *)user_memory - memory;
    uint16_t block;
    for (block = first_block; block < first_block + nb_blocks; block++)
        status[block] = FREE;
}