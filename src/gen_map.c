/*
** EPITECH PROJECT, 2019
** world
** File description:
** generates map
*/

#include "my.h"

void gen_map(float *map, int size, float freq, int depth)
{
    int r = rand() % 255;
    int height_mult = 10;
    float x;
    float y;

    for (int i = 0; i < (size * size); i++) {
        x = (i % size) * freq;
        y = (i / size) * freq;
        map[i] = perlin_noise(x, y, r, depth) * height_mult;
    }
}
