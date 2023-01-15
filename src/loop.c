/*
** EPITECH PROJECT, 2019
** loop
** File description:
** world
*/

#include "my.h"

void destroy_all(win_t *win, map_t *map)
{
    sfRenderWindow_destroy(win->window);
    clear_edit_list(map);
    clear_edit_list(map->water);
    free_map(map);
    free(map->water);
    free(map);
    free(win->info);
    sfClock_destroy(win->rotate_clock);
    free_btns_and_txt(win->btn_list, win->txt_list);
    for (int i = 0; i < 4; ++i)
        free(win->extrems[i]);
    free(win->extrems);
    free(win);
}

int mainloop(map_t *map)
{
    int i = 0;
    map->water = create_map(map->size, map->zoom, 0.01, 10);
    map->water->water_clock = sfClock_create();
    info_t *info = get_map_info(map);
    win_t *win = create_window("My World", info);

    while (sfRenderWindow_isOpen(win->window)) {
        map->display = (info->mode == 1 ? sfLinesStrip : sfQuads);
        map->water->draw = info->has_water;
        map->water->display = map->display;
        if (info->trigger == 1)
            map = reload_map(map, info);
        refresh_points(map->water, &i);
        map->points2d = convert3d_points(map);
        map->water->points2d = convert3d_points(map->water);
        display_window(win, map);
        manage_event(win, map);
    }
    destroy_all(win, map);
    return (0);
}
