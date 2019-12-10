#include "missile.h"
#include "list.h"
#include "heap.h"

#define vt100_move(x, y) ((void)y)
#define serial_puts(s)

static const char skins[2][5] = {
    "|\n\b|",
    ":\n\b:",
};

static T_list lists_missiles[2] = {
    {.start = NULL, .end = NULL},
    {.start = NULL, .end = NULL},
};

void missile_new(unsigned char x, unsigned char y, unsigned char team)
{
    T_missile *p_missile = heap_malloc(sizeof(T_missile));
    if (p_missile != NULL)
    {
        p_missile->x = x;
        p_missile->y = y;
        p_missile->skin = skins[team];

        list_append(
            &lists_missiles[team],
            list_create_element(p_missile));
    }
}

static void missile_draw(T_missile *p_missile)
{
    vt100_move(p_missile->x, p_missile->y);
    serial_puts(p_missile->skin);
}

void missile_draw_all(void)
{
    list_map(
        &lists_missiles[ALLY],
        (T_function)missile_draw);
    list_map(
        &lists_missiles[ENEMY],
        (T_function)missile_draw);
}