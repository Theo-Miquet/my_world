/*
** EPITECH PROJECT, 2019
** lib
** File description:
** malloc and copy a string
*/

#include "my.h"

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *res = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len; i++)
        res[i] = src[i];
    res[len] = '\0';
    return (res);
}
