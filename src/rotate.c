/*
** EPITECH PROJECT, 2019
** rotate
** File description:
** world
*/

#include "my.h"

void rotate_point(sfVector3f *pt, sfVector3f center, float angle)
{
    float x1 = pt->x - center.x;
    float y1 = pt->y - center.y;
    float x2 = x1 * cos(RAD(angle)) - y1 * sin(RAD(angle));
    float y2 = x1 * sin(RAD(angle)) + y1 * cos(RAD(angle));

    pt->x = x2 + center.x;
    pt->y = y2 + center.y;
}

void rotate_map(map_t *map, float angle)
{
    sfVector3f center;

    map->rotation += angle;
    if (map->rotation > 360)
        map->rotation = 1;
    else if (map->rotation < 0)
        map->rotation = 359;
    center.x = map->points3d[(map->size - 1 ) / 2][(map->size - 1 ) / 2].x;
    center.y = map->points3d[(map->size - 1 ) / 2][(map->size - 1 ) / 2].y;
    center.z = 0;
    for (int i = 0; i < map->size; ++i) {
        for (int j = 0; j < map->size; ++j) {
            rotate_point(&(map->points3d[i][j]), center, angle);
            rotate_point(&(map->water->points3d[i][j]), center, angle);
        }
    }
}