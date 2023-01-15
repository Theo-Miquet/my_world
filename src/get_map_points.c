/*
** EPITECH PROJECT, 2019
** world
** File description:
** points
*/

#include "my.h"

void refresh_heights(map_t *water)
{
    int size = water->size;

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            water->points3d[y][x].z = water->map_heights[x + y * size]
                    * water->zoom;
        }
    }
}

void get_map_points(sfVector3f **res, float *map_height, int size, int zoom)
{
    int k = 0;
    sfVector3f midle_screen = convert_2d_3d((sfVector2f){1920/2, 1080/2});
    int dx = midle_screen.x - (size * zoom)/2;
    int dy = midle_screen.y - (size * zoom)/2;

    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            res[y][x] = (sfVector3f){x * zoom + dx, y * zoom + dy,
            map_height[k] * zoom};
            k++;
        }
    }
}
