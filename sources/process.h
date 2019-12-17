#ifndef _PROCESS_H_
#define _PROCESS_H_

#include <stdint.h>

#define PROCESS_NAME_LENGTH (8)

struct process;
typedef uint8_t (*process_entry_point_t)(struct process *context);

typedef struct process
{
    uint8_t name[PROCESS_NAME_LENGTH];
    uint8_t priority;
    process_entry_point_t entry_point;
    uint32_t lineno;
    void *user_context;
} T_process;

T_process *process_create(
    const uint8_t *name,
    const process_entry_point_t entry_point,
    void *const user_context);
void process_destroy(T_process *process);

#define _COROUTINE_FINISHED (0)
#define _COROUTINE_INTERRUPTED (42)

#define COROUTINE_START      \
    switch (context->lineno) \
    {                        \
    case 0:

#define COROUTINE_RESCHEDULE       \
    context->lineno = __LINE__;    \
    return _COROUTINE_INTERRUPTED; \
    case __LINE__:

#define COROUTINE_WAIT_UNTIL(condition) \
    context->lineno = __LINE__;         \
    case __LINE__:                      \
        if (!(condition))               \
        return _COROUTINE_INTERRUPTED

#define COROUTINE_WAIT_WHILE(condition) \
    COROUTINE_WAIT_UNTIL(!(condition))

#define COROUTINE_END    \
    }                    \
    context->lineno = 0; \
    return _COROUTINE_FINISHED

#endif /* _PROCESS_H_ */