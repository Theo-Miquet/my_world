/*
** EPITECH PROJECT, 2019
** map
** File description:
** world
*/

#include "my.h"

sfVector3f **malloc_map(int size)
{
    sfVector3f **res = malloc(sizeof(sfVector3f *) * (size + 1));

    for (int y = 0; y < size; y++)
        res[y] = malloc(sizeof(sfVector3f) * (size + 1));
    res[size] = NULL;
    return (res);
}

map_t *create_map(int size, int zoom, float freq, int depth)
{
    map_t *res = malloc(sizeof(map_t));

    res->size = size;
    res->draw = 1;
    res->display = sfQuads;
    res->zoom = zoom;
    res->depth = depth;
    res->freq = freq * 100;
    res->rotation = 45;
    res->map_heights = malloc(sizeof(float) * (size * size));
    gen_map(res->map_heights, size, freq, depth);
    res->points3d = malloc_map(size);
    get_map_points(res->points3d, res->map_heights, size, zoom);
    res->points2d = convert3d_points(res);
    res->water_clock = NULL;
    res->edits = malloc(sizeof(float *) * 20);
    for (int i = 0; i < 20; ++i)
        res->edits[i] = NULL;
    res->edit_index = -1;
    return (res);
}

void free_map(map_t *map)
{
    for (int i = 0; i < map->size; i++) {
        free(map->points2d[i]);
        free(map->points3d[i]);
    }
    free(map->points2d);
    free(map->points3d);
    free(map->map_heights);
    if (map->water_clock != NULL)
        sfClock_destroy(map->water_clock);
}

map_t *reload_map(map_t *map, info_t *info)
{
    info->trigger = 0;
    clear_edit_list(map);
    clear_edit_list(map->water);
    free_map(map->water);
    free_map(map);
    map_t *new_map = create_map(info->size, map->zoom, (float)info->freq/100,
                                info->depth);
    new_map->water = create_map(new_map->size, new_map->zoom, 0.01, 10);
    new_map->water->water_clock = sfClock_create();
    free(map->water);
    free(map);
    add_edit(new_map);
    return new_map;
}

info_t *get_map_info(map_t *map)
{
    info_t *new = malloc(sizeof(info_t));

    new->freq = map->freq;
    new->has_water = 1;
    new->depth = map->depth;
    new->size = map->size;
    new->trigger = 0;
    new->mode = 0;
}
