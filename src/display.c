/*
** EPITECH PROJECT, 2019
** disp
** File description:
** world
*/

#include "my.h"

void display_buttons(win_t *win)
{
    button_t *current_b = win->btn_list;

    while (current_b != NULL) {
        sfRenderWindow_drawSprite(win->window, current_b->sprite, NULL);
        current_b = current_b->next;
    }
}

void display_texts(win_t *win)
{
    txt_t *current_t = win->txt_list;
    char *txt_disp = "";

    while (current_t != NULL) {
        if (current_t->bind != NULL) {
            txt_disp = nb_to_str(*current_t->bind);
            txt_disp = my_concat(current_t->base, txt_disp);
            sfText_setString(current_t->text, txt_disp);
            free(txt_disp);
        } else
            sfText_setString(current_t->text, current_t->base);
        sfRenderWindow_drawText(win->window, current_t->text, NULL);
        current_t = current_t->next;
    }
}

void display_window(win_t *win, map_t *map)
{
    sfRenderWindow_clear(win->window, sfColor_fromRGB(0, 0, 50));
    render_map(map, win->window);
    sfRenderWindow_drawRectangleShape(win->window, win->back, NULL);
    display_buttons(win);
    display_texts(win);
    sfRenderWindow_display(win->window);
}