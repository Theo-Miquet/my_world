/*
** EPITECH PROJECT, 2018
** event
** File description:
** runner
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System/Types.h>
#include <stdlib.h>
#include "my.h"

void rotate_event(map_t *map, double offset)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        rotate_map(map, -1 * (float)offset);
    } else if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        rotate_map(map, 1 * (float)offset);
    }
}

void terraform_event(map_t *map, sfVector2i mouse, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed
        && sfMouse_isButtonPressed(sfMouseLeft)) {
        get_clicked_point(mouse, map, 1);
    }
    else if (event.type == sfEvtMouseButtonPressed
    && sfMouse_isButtonPressed(sfMouseRight)) {
        get_clicked_point(mouse, map, 0);
    }
}

double get_offset(win_t *win)
{
    sfTime time = sfClock_getElapsedTime(win->rotate_clock);
    static double prev_frame = 0;
    double offset = fabs(time.microseconds - prev_frame) / 50000.0;

    prev_frame = time.microseconds;
    return offset;
}

void manage_event(win_t *win, map_t *map)
{
    sfEvent event;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win->window);
    int btn_press = 0;
    double offset = get_offset(win);

    rotate_event(map, offset);
    while (sfRenderWindow_pollEvent(win->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(win->window);
        if (event.type == sfEvtMouseButtonPressed
            && sfMouse_isButtonPressed(sfMouseLeft)) {
            btn_press = click_check(map, win, mouse);
        }
        if (btn_press == 0)
            terraform_event(map, mouse, event);
        hover_buttons(win, mouse);
        btn_press = 0;
    }
}