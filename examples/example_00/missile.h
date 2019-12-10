#ifndef MISSILE_H
#define MISSILE_H

#define ALLY (0)
#define ENEMY (1)

typedef struct
{
    unsigned char x;
    unsigned char y;
    const char *skin;
} T_missile;

void missile_new(unsigned char x, unsigned char y, unsigned char team);
void missile_draw_all(void);

#endif /* MISSILE_H */