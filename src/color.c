/*
** EPITECH PROJECT, 2019
** world
** File description:
** color
*/

#include "my.h"

float get_average_height(map_t *map, int args[4])
{
    float res = 0;
    int a = args[2];
    int b = args[3];

    res += map->points3d[args[0]][args[1]].z;
    res += map->points3d[args[0] + a][args[1]].z;
    res += map->points3d[args[0] + a][args[1] + b].z;
    res += map->points3d[args[0]][args[1] + b].z;
    return res/4;
}

sfColor get_color(sfVector3f pt, map_t *map, int args[4])
{
    float i = get_average_height(map, args)/(map->zoom * 10);

    if (i > 0.4 && i < 0.7)
        return sfColor_fromRGB(83 * i, 255 - (189 * i), 40 * i);
    else if (i >= 0.7)
        return sfColor_fromRGB(250 * i, 255 * i, 255 * i);
    else
        return sfColor_fromRGB(250 * i + 140, 250 * i + 140, 100 * i);
}

sfColor get_color_water(sfVector3f pt, map_t *map, int args[4])
{
    float i = get_average_height(map, args)/(map->zoom * 10);

    return sfColor_fromRGBA(150 * i, 150 * i, 255 * i + 100, 180);
}
