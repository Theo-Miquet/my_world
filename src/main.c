/*
** EPITECH PROJECT, 2019
** world
** File description:
** main
*/

#include "my.h"

void print_usage(void)
{
    my_putstr("USAGE\n\t./my_world [-h / file]\nDESCRIPTION\n", 1);
    my_putstr("\t-h\tCommand usage.\n\tfile\t", 1);
    my_putstr("Open a world file generated by the save\n", 1);
    my_putstr("\t    \tbutton in the program.\n", 1);
}

int main(int ac, char **av)
{
    int size = 32;
    int zoom = 20;
    float freq = 0.15;
    int depth = 10;
    map_t *map;

    if (ac > 2) {
        my_putstr("Too much arguments, try \"./my_world -h\"\n", 2);
        return (84);
    } else if (ac == 2) {
        if (my_strcmp(av[1], "-h") == 1) {
            print_usage();
            return (0);
        } else
            map = open_map(av[1]);
    } else
        map = (create_map(size, zoom, freq, depth));
    if (!map) return (84);
    add_edit(map);
    return (mainloop(map));
}
