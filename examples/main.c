#include "heap.h"
#include "list.h"
#include "missile.h"

typedef struct
{
    unsigned char temperature;
} T_aliment;

void cuire(void *data)
{
    T_aliment *aliment = (T_aliment *)data;
    aliment->temperature++;
}

int main(void)
{
    heap_init();

    unsigned short *zone_reservee;

    /* donne moi une zone de 200 octets contigus */
    zone_reservee = heap_malloc(200);

    if (zone_reservee != NULL)
    {
        /* utilisation */
        zone_reservee[4] = 12;
        zone_reservee[5] = 123;

        /* liberation */
        heap_free(zone_reservee, 200);
    }

    T_list ma_liste = {.start = NULL, .end = NULL};
    T_aliment carotte = {.temperature = 20};
    T_element *element = list_create_element(&carotte);
    list_append(&ma_liste, element);
    list_map(&ma_liste, cuire);

    missile_new(10, 5, ENEMY);

    return 0;
}