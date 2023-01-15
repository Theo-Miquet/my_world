/*
** EPITECH PROJECT, 2018
** nb_to_array
** File description:
** lib
*/

#include <stdlib.h>
#include "my.h"

int nb_digit(long int nb)
{
    int count = 0;

    while (nb > 0)
    {
        nb /= 10;
        count++;
    }
    return count;
}

char *nb_to_str(int nb)
{
    char *str = malloc(sizeof(char) * (nb_digit(nb) + 1));
    int temp;
    int i = 0;

    if (nb == 0)
        return "0";
    while (nb > 0) {
        temp = nb % 10;
        str[i] = temp + '0';
        nb -= temp;
        nb /= 10;
        i++;
    }
    str[i] = '\0';
    my_revstr(str);
    str[i] = '\0';
    return str;
}