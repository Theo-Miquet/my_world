/*
** EPITECH PROJECT, 2019
** gui
** File description:
** world
*/

#include "my.h"

sfVector2i pos(int x, int y)
{
    return (sfVector2i){x, y};
}

void add_button(win_t *win, button_t *btn, int *extrems, float scale)
{
    button_t *current = win->btn_list;

    btn->extrems = extrems;
    if (extrems[0] == 0 && extrems[1] == 2)
        btn->link_value = 1;
    color_boolean_btn(btn, win);
    sfSprite_setScale(btn->sprite, (sfVector2f){scale, scale});
    if (current == NULL) {
        win->btn_list = btn;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = btn;
}

button_t *create_btn(sfVector2i pos, char *src, int *link,
        void (*fct)(map_t *, int *, int, int *extrems))
{
    button_t *new_btn = malloc(sizeof(button_t));

    new_btn->x = pos.x;
    new_btn->y = pos.y;
    new_btn->texture = sfTexture_createFromFile(src, NULL);
    new_btn->sprite = sfSprite_create();
    new_btn->fct = fct;
    new_btn->modif_value = link;
    if (my_strcmp(src, "resources/plus.png") == 1)
        new_btn->link_value = 1;
    else if (my_strcmp(src, "resources/minus.png") == 1)
        new_btn->link_value = -1;
    new_btn->next = NULL;
    sfSprite_setTexture(new_btn->sprite, new_btn->texture, sfTrue);
    sfSprite_setPosition(new_btn->sprite, (sfVector2f){pos.x, pos.y});
    return new_btn;
}

void add_txt(win_t *win, txt_t *t)
{
    txt_t *current = win->txt_list;

    if (current == NULL) {
        win->txt_list = t;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = t;
}

txt_t *create_txt(sfVector2i pos, int *bind, char *base)
{
    txt_t *new_txt = malloc(sizeof(txt_t));
    sfFont *font = sfFont_createFromFile("resources/8bit.ttf");

    new_txt->base = base;
    new_txt->next = NULL;
    new_txt->bind = bind;
    new_txt->text = sfText_create();
    sfText_setFont(new_txt->text, font);
    sfText_setPosition(new_txt->text, (sfVector2f){pos.x, pos.y});
    sfText_setColor(new_txt->text, sfWhite);
    sfText_setCharacterSize(new_txt->text, 20);
    return new_txt;
}