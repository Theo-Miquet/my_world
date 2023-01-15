/*
** EPITECH PROJECT, 2019
** lib
** File description:
** str to int
*/

#include "my.h"
#include <math.h>

int my_atoi(char *str)
{
    int n = 0;
    int compt = 0;

    while (is_int(str[compt]) == 1)
        compt++;
    if (compt + 1 == my_strlen(str)) {
        for (int i = 0; i < compt; i++)
            n += ((str[compt - i - 1] - '0')) * (pow(10, i));
    }
    return (n);
}
