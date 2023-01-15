/*
** EPITECH PROJECT, 2019
** water
** File description:
** world
*/

#include "my.h"

void wave(map_t *water, int *i, float w_height)
{
    float wave[] = {0, 0.1, 0.2, 0.3, 0.5, 0.3, 0.2, 0.1, 0};
    float *map = water->map_heights;
    int size = water->size;

    (*i)++;
    (*i) %= 8;
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++)
            map[y * size + x] = wave[(x + y + (*i)) % 8] + w_height;
    }
}

void refresh_points(map_t *map, int *i)
{
    sfTime time = sfClock_getElapsedTime(map->water_clock);

    if (time.microseconds / 100000.0 < 1)
        return;
    wave(map, i, 3.5);
    refresh_heights(map);
    sfClock_restart(map->water_clock);
}