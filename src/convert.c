/*
** EPITECH PROJECT, 2019
** world
** File description:
** vertex
*/

#include "my.h"

sfVector2f convert_3d_2d(sfVector3f pt)
{
    sfVector2f instance;

    instance.x = cos(RAD(45)) * pt.x - cos(RAD(45)) * pt.y;
    instance.y = sin(RAD(35)) * pt.y + sin(RAD(35)) * pt.x - pt.z;
    return instance;
}

sfVector3f convert_2d_3d(sfVector2f pt)
{
    sfVector3f r;

    r.y = pt.x / (cos(RAD(45)) * ((pt.y - sin(RAD(35)))/sin(RAD(35)) - 1));
    r.x = (pt.y - sin(RAD(35)) * r.y) / sin(RAD(35));
    r.z = 0;
    return r;
}

sfVector2f **convert3d_points(map_t *map)
{
    sfVector2f **res = malloc(sizeof(sfVector2f *) * (map->size + 1));

    for (int y = 0; y < map->size; ++y) {
        res[y] = malloc(sizeof(sfVector2f) * (map->size + 1));
        for (int x = 0; x < map->size; ++x) {
            res[y][x] = convert_3d_2d(map->points3d[y][x]);
        }
    }
    res[map->size] = NULL;
    return res;
}