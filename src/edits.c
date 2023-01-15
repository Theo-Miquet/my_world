/*
** EPITECH PROJECT, 2019
** world
** File description:
** edits
*/

#include "my.h"

void erase_first_elem(float **list)
{
    free(list[0]);
    list[0] = NULL;
    for (int i = 1; i < 20; ++i) {
        list[i - 1] = list[i];
    }
}

int count_edits(float **list)
{
    int i = 0;

    while (i < 20 && list[i] != NULL)
        i++;
    return i;
}

void erase_forwards_elem(float **list, int nb)
{
    int i = nb;

    while (i < 20 && list[i] != NULL) {
        free(list[i]);
        list[i] = NULL;
        i++;
    }
}

void add_edit(map_t *map)
{
    int k = 0;

    map->edit_index++;
    if (map->edit_index == 20) {
        erase_first_elem(map->edits);
        map->edit_index--;
    }
    else if (map->edit_index < count_edits(map->edits))
        erase_forwards_elem(map->edits, map->edit_index);
    k = map->edit_index;
    map->edits[k] = malloc(sizeof(float) * (map->size * map->size + 1));
    for (int i = 0; i < map->size; ++i) {
        for (int j = 0; j < map->size; ++j) {
            map->edits[k][map->size * i + j] = map->points3d[i][j].z;
        }
    }
}

void clear_edit_list(map_t *map)
{
    int i = 0;

    while (i != 20 && map->edits[i] != NULL) {
        free(map->edits[i]);
        i++;
    }
    free(map->edits);
}