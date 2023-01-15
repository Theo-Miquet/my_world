/*
** EPITECH PROJECT, 2019
** win
** File description:
** world
*/

#include "my.h"

sfRenderWindow *new_window(u_int width, u_int height, u_int bpp, char *t)
{
    sfRenderWindow *w;

    sfVideoMode video = {width, height, bpp};
    w = sfRenderWindow_create(video, t, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(w, 60);
    return w;
}

int **create_max(void)
{
    int size = 4;
    int **res = malloc(sizeof(int *) * size);

    for (int i = 0; i < size; i++) {
        res[i] = malloc(sizeof(int) * 2);
        res[i][0] = 0;
        res[i][1] = 25;
    }
    res[0][0] = 16;
    res[0][1] = 64;
    res[3][0] = 0;
    res[3][1] = 2;
    return res;
}

void add_gui_map(win_t *win, info_t *info)
{
    int y = 100;
    char *base_txt[3] = {"Size: ", "Frequence: ", "Depth: "};
    int **extrem = win->extrems;
    int *map_values[4] = {&info->size, &info->freq, &info->depth,
                          &info->trigger};
    for (int i = 0; i < 3; ++i) {
        add_button(win, create_btn(pos(1820, y * (i + 1)),
                "resources/plus.png", map_values[i], add_value), extrem[i], 2);
        add_txt(win, create_txt(pos(1620, y * (i + 1) + 5), map_values[i],
                                base_txt[i]));
        add_button(win, create_btn(pos(1520, y * (i + 1)),
                "resources/minus.png" ,
                map_values[i], add_value), extrem[i], 2);
    }
    add_button(win, create_btn(pos(1615, y * 8), "resources/genmap.png",
            map_values[3], add_value), extrem[3], 1);
    add_button(win, create_btn(pos(1615, y * 9), "resources/savemap.png",
            map_values[3], save_world), extrem[3], 1);
}

void add_gui_tool(win_t *win, info_t *info)
{
    int y = 100;
    int **extrem = win->extrems;
    int *map_values[2] = {&info->has_water, &info->mode};

    add_button(win, create_btn(pos(1560, y * 4.5),
            "resources/poly.png", map_values[1], add_value), extrem[3], 1);
    add_button(win, create_btn(pos(1695, y * 4.5),
            "resources/water.png", map_values[0], add_value), extrem[3], 1);
    add_button(win, create_btn(pos(1630, y * 6.5),
            "resources/reset.png", NULL, reset), extrem[0], 1);
    add_button(win, create_btn(pos(1578, y * 6.5),
            "resources/undo.png", NULL, undo), extrem[0], 1);
    add_button(win, create_btn(pos(1752, y * 6.5),
            "resources/redo.png", NULL, redo), extrem[0], 1);
    add_txt(win, create_txt(pos(1540, y * 5.4), NULL,
            "Left  click -> push terrain.\nRight click -> pull terrain.\n"
            "Left  |  Right -> rotate map"));
}

win_t *create_window(char *title, info_t *info)
{
    win_t *win = malloc(sizeof(win_t));

    win->window = new_window(1920, 1080, 32, title);
    win->info = info;
    win->rotate_clock = sfClock_create();
    win->btn_list = NULL;
    win->txt_list = NULL;
    win->extrems = create_max();
    add_gui_map(win, info);
    add_gui_tool(win, info);
    win->back = sfRectangleShape_create();
    sfRectangleShape_setFillColor(win->back, sfColor_fromRGBA(255, 255, 255,
            70));
    sfRectangleShape_setPosition(win->back, (sfVector2f){1450, 0});
    sfRectangleShape_setSize(win->back, (sfVector2f){470, 1080});
    return win;
}