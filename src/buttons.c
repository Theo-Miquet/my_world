/*
** EPITECH PROJECT, 2019
** btn
** File description:
** world
*/

#include "my.h"

void free_btns_and_txt(button_t *b, txt_t *t)
{
    button_t *current_b = b;
    button_t *temp_b;
    txt_t *current_t = t;
    txt_t *temp_t;

    while (current_b != NULL) {
        temp_b = current_b->next;
        sfSprite_destroy(current_b->sprite);
        sfTexture_destroy(current_b->texture);
        free(current_b);
        current_b = temp_b;
    }
    while (current_t != NULL) {
        temp_t = current_t->next;
        sfText_destroy(current_t->text);
        free(current_b);
        current_t = temp_t;
    }
}

void color_boolean_btn(button_t *btn, win_t *win)
{
    sfColor enable = sfColor_fromRGB(0, 255, 0);
    sfColor disable = sfColor_fromRGB(255, 0, 0);

    if (btn->extrems[1] != 2 || btn->modif_value == &win->info->trigger)
        return;
    else if (sfSprite_getColor(btn->sprite).r != enable.r)
        sfSprite_setColor(btn->sprite, enable);
    else
        sfSprite_setColor(btn->sprite, disable);
}

int click_check(map_t *map, win_t *win, sfVector2i mouse)
{
    button_t *current = win->btn_list;
    int sx = 0;
    int sy = 0;

    while (current != NULL) {
        sx = (int)(sfTexture_getSize(current->texture).x *
                sfSprite_getScale(current->sprite).x);
        sy = (int)(sfTexture_getSize(current->texture).y *
                sfSprite_getScale(current->sprite).y);
        if ((mouse.x > current->x && mouse.x < current->x + sx) &&
            (mouse.y > current->y && mouse.y < current->y + sy)) {
            current->fct(map, current->modif_value, current->link_value,
                    current->extrems);
            color_boolean_btn(current, win);
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void manage_colors(sfColor *h, sfColor *n)
{
    h->a = 200;
    n->a = 255;
}

void hover_buttons(win_t *win, sfVector2i mouse)
{
    button_t *current = win->btn_list;
    sfColor hover_color;
    sfColor norm_color;
    int sx = 0;
    int sy = 0;

    while (current != NULL) {
        hover_color = sfSprite_getColor(current->sprite);
        norm_color = hover_color;
        manage_colors(&hover_color, &norm_color);
        sx = (int)(sfTexture_getSize(current->texture).x *
                sfSprite_getScale(current->sprite).x);
        sy = (int)(sfTexture_getSize(current->texture).y *
                sfSprite_getScale(current->sprite).y);
        if ((mouse.x > current->x && mouse.x < current->x + sx) &&
            (mouse.y > current->y && mouse.y < current->y + sy)) {
            sfSprite_setColor(current->sprite, hover_color);
        } else
            sfSprite_setColor(current->sprite, norm_color);
        current = current->next;
    }
}