/*
** EPITECH PROJECT, 2019
** world
** File description:
** open map file check for errors and gen map
*/

#include "my.h"
#include <unistd.h>

map_t *find_args(char *line)
{
    float a[3] = {0, 0, 0};
    char *temp = NULL;

    for (int i = 0; i < 3; i++) {
        temp = my_strdupline(line, i, ';');
        if (temp && !i) {
            a[i] = str_to_float(temp);
            a[i] = (a[i] > 15 && a[i] < 65) ? a[i] : 0;
            free(temp);
        } else if (temp) {
            a[i] = str_to_float(temp);
            a[0] = (a[i] >= 0 && a[i] < 26) ? a[0] : 0;
            free(temp);
        } else
            a[0] = 0;
    }
    free(line);
    if (a[0])
        return (create_map(a[0], 20, a[1], a[2]));
    return (NULL);
}

int fill_map_heights(map_t *map, char *line, int s, int i)
{
    char *temp = NULL;
    float f = 0;
    int zoom = map->zoom;

    for (int j = 0; j < s; j++) {
        temp = my_strdupline(line, j, ' ');
        if (temp) {
            f = str_to_float(temp);
            map->map_heights[i * s + j] = f / zoom;
        } else
            f = -1;
        free(temp);
        if (f < 0 || f > 200)
            return (-1);
    }
    return (0);
}

map_t *open_map(char *path)
{
    int fd = open(path, O_RDONLY);
    char *line = get_next_line(fd);
    map_t *map = find_args(line);

    if (!map) return (map);
    for (int i = 0; i < map->size; i++) {
        line = get_next_line(fd);
        if (fill_map_heights(map, line, map->size, i)) {
            free_map(map);
            return (NULL);
        }
        free(line);
    }
    close (fd);
    get_map_points(map->points3d, map->map_heights, map->size, map->zoom);
    map->points2d = convert3d_points(map);
    return (map);
}
