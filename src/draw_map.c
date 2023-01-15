/*
** EPITECH PROJECT, 2019
** draw
** File description:
** world
*/

#include "my.h"

void get_rotation_side(map_t *map, int *a, int *b)
{
    if (map->rotation > 0 && map->rotation <= 90) {
        *a = 1;
        *b = 1;
        return;
    } if (map->rotation > 90 && map->rotation <= 180) {
        *a = -1;
        *b = 1;
        return;
    } if (map->rotation > 180 && map->rotation <= 270) {
        *a = -1;
        *b = -1;
        return;
    } if (map->rotation > 270) {
        *a = 1;
        *b = -1;
        return;
    }
}

sfVertex add_vertex(map_t *map, int i, int j, sfColor c)
{
    return (sfVertex) {.position = map->points2d[i][j], .color = c};
}

void draw_quad(map_t *map, const int *args, sfRenderWindow *window, sfColor c)
{
    sfVertexArray *quad_draw = sfVertexArray_create();
    int i = args[0];
    int j = args[1];
    int a = args[2];
    int b = args[3];

    if (map->draw == 0)
        return;
    a = (i == map->size ? 0 : a);
    b = (j == map->size ? 0 : b);
    sfVertexArray_append(quad_draw, add_vertex(map, i, j, c));
    sfVertexArray_append(quad_draw, add_vertex(map, i + a, j, c));
    sfVertexArray_append(quad_draw, add_vertex(map, i + a, j + b, c));
    sfVertexArray_append(quad_draw, add_vertex(map, i, j + b, c));
    sfVertexArray_setPrimitiveType(quad_draw, map->display);
    sfRenderWindow_drawVertexArray(window, quad_draw, NULL);
    sfVertexArray_clear(quad_draw);
    sfVertexArray_destroy(quad_draw);
}

void render_first(map_t *map, int i, int j, sfRenderWindow *win)
{
    sfColor l;
    sfColor w;
    int args[4] = {i, j, 0, 0};

    get_rotation_side(map, &args[2], &args[3]);
    l = get_color(map->points3d[i][j], map, args);
    w = get_color_water(map->points3d[i][j], map, args);
    if (map->points3d[i][j].z >= map->water->points3d[i][j].z) {
        w.a = 0;
        draw_quad(map->water, args, win, w);
        draw_quad(map, args, win, l);
    } else {
        draw_quad(map, args, win, l);
        draw_quad(map->water, args, win, w);
    }
}

void render_map(map_t *map, sfRenderWindow *window)
{
    int a = 0;
    int b = 0;
    int resa = 0;
    int resb = 0;

    get_rotation_side(map, &a, &b);
    resa = (a < 0 ? map->size - 1 : 0);
    resb = (b < 0 ? map->size - 1 : 0);
    for (int i = 0; i < map->size - 1; i++) {
        for (int j = 0; j < map->size - 1; j++) {
            render_first(map, resa + (i * a), resb + (j * b), window);
        }
    }
}
