/*
** EPITECH PROJECT, 2019
** lib
** File description:
** check if char is int
*/

int is_int(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}
