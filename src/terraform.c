/*
** EPITECH PROJECT, 2019
** terraform
** File description:
** world
*/

#include "my.h"

void pull_point(map_t *map, sfVector3f c)
{
    sfVector3f *p;
    float distance;

    for (int i = 0; i < map->size; ++i) {
        for (int j = 0; j < map->size; ++j) {
            p = &map->points3d[i][j];
            distance = sqrtf(pow(p->x - c.x, 2) + pow(p->y - c.y, 2));
            p->z += (distance < 5 * map->zoom ?
                    map->zoom * (1 - distance/100) : 0);
            p->z = (p->z > map->zoom * 10 ? map->zoom * 10 : p->z);
        }
    }
}

void push_point(map_t *map, sfVector3f c)
{
    sfVector3f *p;
    float distance;

    for (int i = 0; i < map->size; ++i) {
        for (int j = 0; j < map->size; ++j) {
            p = &map->points3d[i][j];
            distance = sqrtf(pow(p->x - c.x, 2) + pow(p->y - c.y, 2));
            p->z -= (distance < 5 * map->zoom ?
                    map->zoom * (1 - distance/100) : 0);
            p->z = (p->z < 0 ? 0 : p->z);
        }
    }
}

void terra_points(int i, map_t *map, sfVector2i mouse, int mode)
{
    sfVector2f pt;

    for (int j = 0; j < map->size; ++j) {
        pt = map->points2d[i][j];
        if (sqrtf(pow(pt.x - mouse.x, 2) + pow(pt.y - mouse.y, 2)) < 10
            && mode == 1) {
            push_point(map, map->points3d[i][j]);
            add_edit(map);
            return;
        }
        else if (sqrtf(pow(pt.x - mouse.x, 2) + pow(pt.y - mouse.y, 2)) < 10
        && mode == 0) {
            pull_point(map, map->points3d[i][j]);
            add_edit(map);
            return;
        }
    }
}

void get_clicked_point(sfVector2i mouse, map_t *map, int mode)
{
    for (int i = 0; i < map->size; ++i) {
        terra_points(i, map, mouse, mode);
    }
}