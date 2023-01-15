/*
** EPITECH PROJECT, 2019
** float
** File description:
** lib
*/

#include "my.h"

char *float_to_str(float nb)
{
    char *res;
    int e = (int)nb;
    float d = nb - e;

    while (d - (int)d != 0)
        d *= 10;
    res = my_concat(nb_to_str(e), ".");
    res = my_concat(res, nb_to_str((int)d));
    return (res);
}

float str_to_float(const char *str)
{
    int res = 0;
    int num;
    float f = 1;
    int p = 0;

    for (int i = 0; str[i] && i < 10; i++){
        if (str[i] == '.' || str[i] == ',') {
            p++;
            i++;
        }
        num = str[i] - '0';
        if (num >= 0 && num <= 9 && p < 2) {
            if (p) f /= 10;
            res = res * 10 + num;
        } else
            return (-1);
    }
    f *= (float)res;
    return (f);
}
