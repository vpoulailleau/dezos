#ifndef _PROCESS_H_
#define _PROCESS_H_

#define PROCESS_NAME_LENGTH 8

struct process;
typedef void (*process_entry_point_t)(struct process *context);

typedef struct process
{
    unsigned char name[PROCESS_NAME_LENGTH];
    char priority;
    process_entry_point_t entry_point;
    unsigned long execution_time;
    unsigned long timer;
    void *user_context;
} T_process;

T_process *process_create(
    const unsigned char *name,
    const process_entry_point_t entry_point,
    void *const user_context);
void process_destroy(T_process *process);

#endif /* _PROCESS_H_ */