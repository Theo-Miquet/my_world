/*
** EPITECH PROJECT, 2019
** concat
** File description:
** str
*/

#include <stdlib.h>
#include "my.h"

char *my_concat(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    int len = my_strlen(s1) + my_strlen(s2);
    char *res = NULL;

    if (len)
        res = malloc(sizeof(char) * (len + 1));
    else
        return (NULL);
    if (s1) {
        for ( ; s1[i] != '\0'; i++)
            res[i] = s1[i];
        if (!s2) res[i] = '\0';
    }
    if (s2) {
        for ( ; s2[j] != '\0'; j++)
            res[j + i] = s2[j];
        res[i + j] = '\0';
    }
    return (res);
}
