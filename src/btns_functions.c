/*
** EPITECH PROJECT, 2019
** wolrd
** File description:
** btn
*/

#include "my.h"

void add_value(map_t *map, int *var, int value, int *extrems)
{
    if (*var + value < extrems[0] || *var + value > extrems[1])
        return;
    *var += value;
    if (*var == extrems[1] && extrems[1] == 2)
        *var = 0;
}

void undo(map_t *map, int *var, int value, int *extrems)
{
    int k = 0;

    map->edit_index--;
    if (map->edit_index < 0) {
        map->edit_index = 0;
        return;
    }
    k = map->edit_index;
    for (int i = 0; i < map->size; ++i) {
        for (int j = 0; j < map->size; ++j) {
            map->points3d[i][j].z = map->edits[k][map->size * i + j];
        }
    }
}

void redo(map_t *map, int *var, int value, int *extrems)
{
    int k = 0;

    if (map->edit_index == 19 || map->edits[map->edit_index + 1] == NULL)
        return;
    map->edit_index++;
    k = map->edit_index;
    for (int i = 0; i < map->size; ++i) {
        for (int j = 0; j < map->size; ++j) {
            map->points3d[i][j].z = map->edits[k][map->size * i + j];
        }
    }
}

void reset(map_t *map, int *var, int value, int *extrems)
{
    for (int i = 0; i < map->size; ++i) {
        for (int j = 0; j < map->size; ++j) {
            map->points3d[i][j].z = map->map_heights[map->size * i + j] *
                    map->zoom;
        }
    }
}