/*
** EPITECH PROJECT, 2019
** my
** File description:
** lib
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <math.h>

#define RAD(angleDegrees) ((angleDegrees) * M_PI / 180.0)

typedef struct map map_t;
typedef struct win win_t;
typedef struct button button_t;

struct button {
    sfSprite *sprite;
    sfTexture *texture;
    char *file;
    int x;
    int y;
    int *extrems;
    int *modif_value;
    int link_value;
    void (*fct)(map_t *, int *v, int val, int *extrems);
    button_t *next;
};

struct txt {
    sfText *text;
    char *base;
    int *bind;
    struct txt *next;
}; typedef struct txt txt_t;

struct info {
    int depth;
    int freq;
    int size;
    int mode;
    int has_water;
    int trigger;
}; typedef struct info info_t;

struct win
{
    int **extrems;
    sfRenderWindow *window;
    sfClock *rotate_clock;
    button_t *btn_list;
    txt_t *txt_list;
    sfRectangleShape *back;
    struct info *info;
};

struct map
{
    float freq;
    int depth;
    int size;
    int zoom;
    float rotation;
    int draw;
    float *map_heights;
    float **edits;
    int edit_index;
    sfPrimitiveType display;
    sfVector2f **points2d;
    sfVector3f **points3d;
    sfClock *water_clock;
    map_t *water;
};

win_t *create_window(char *, info_t *info);
void add_value(map_t *map, int *var, int value, int extrems[2]);

void reset(map_t *map, int *var, int value, int *extrems);
void add_edit(map_t *map);
void clear_edit_list(map_t *map);
void undo(map_t *map, int *var, int value, int *extrems);
void redo(map_t *map, int *var, int value, int *extrems);
void save_world(map_t *map, int *var, int value, int *extrems);

void check_buttons(map_t *map, win_t *win, sfVector2i mouse);
int click_check(map_t *map, win_t *win, sfVector2i mouse);
void hover_buttons(win_t *win, sfVector2i mouse);
void add_button(win_t *win, button_t *btn, int *extrems, float scale);
button_t *create_btn(sfVector2i pos, char *src, int *link, void (*fct)(map_t *,
        int *, int, int *extrems));
void color_boolean_btn(button_t *btn, win_t *win);
void add_txt(win_t *win, txt_t *t);
txt_t *create_txt(sfVector2i pos, int *bind, char *base);
void display_window(win_t *win, map_t *map);
void free_btns_and_txt(button_t *b, txt_t *t);
sfVector2i pos(int x, int y);

float perlin_noise(float, float, int, int);
void gen_map(float *, int, float, int);
sfVector2f **convert3d_points(map_t *map);
void render_map(map_t *map, sfRenderWindow *window);
void get_map_points(sfVector3f **, float *, int, int);
void rotate_map(map_t *map, float angle);
void zoom_map(map_t *map, int offset);
map_t *create_map(int size, int zoom, float freq, int depth);
map_t *reload_map(map_t *map, info_t *info);
info_t *get_map_info(map_t *map);
void refresh_points(map_t *map, int *i);
void free_map(map_t *map);
void wave(map_t *, int *, float);
void refresh_points(map_t *, int *);
void refresh_heights(map_t *);
sfColor get_color(sfVector3f, map_t *, int args[4]);
sfColor get_color_water(sfVector3f, map_t *, int args[4]);
sfVector3f **malloc_map(int);
sfVector3f convert_2d_3d(sfVector2f pt);
void get_clicked_point(sfVector2i mouse, map_t *map, int mode);

map_t *read_map(char *);

int mainloop(map_t *);
void manage_event(win_t *win, map_t *map);

int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int nb);
int my_strlen(char const *str);
void my_putstr(char *str, int output);
char *nb_to_str(int nb);
char *my_revstr(char *str);
char *my_concat(char *s1, char *s2);
char *float_to_str(float nb);
float str_to_float(const char *str);
int my_atoi(char *);
int is_int(char);
char *get_file_content(char *);
map_t *open_map(char *);

char *get_next_line(int);
char *my_strdup(const char *);
char *my_strdup_xy(char *, int, int);
char *my_strdupline(char *, int, char);
char *my_strcat(char *, char *);
