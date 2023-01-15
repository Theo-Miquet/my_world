/*
** EPITECH PROJECT, 2019
** save
** File description:
** world
*/

#include <unistd.h>
#include "my.h"

void write_params(map_t *map, int fd)
{
    my_putstr(nb_to_str(map->size), fd);
    my_putstr(";", fd);
    my_putstr(float_to_str(map->freq), fd);
    my_putstr(";", fd);
    my_putstr(nb_to_str(map->depth), fd);
    for (int i = 0; i < map->size; ++i) {
        my_putstr("\n", fd);
        for (int j = 0; j < map->size; ++j) {
            my_putstr(float_to_str(map->points3d[i][j].z), fd);
            my_putstr(" ", fd);
        }
    }
    close(fd);
}

void save_world(map_t *map, int *var, int value, int *extrems)
{
    DIR *instance;
    int fd;
    char *file_name;
    struct dirent *de;
    int count = 1;

    instance = opendir(".");
    de = readdir(instance);
    while (de != NULL) {
        count += (my_strncmp("world_", de->d_name, 6) == 1 ? 1 : 0);
        de = readdir(instance);
    }
    file_name = my_concat("world_", nb_to_str(count));
    file_name = my_concat(file_name, ".legend");
    fd = open(file_name, O_CREAT | O_WRONLY, 0777);
    if (fd != -1)
        write_params(map, fd);
}