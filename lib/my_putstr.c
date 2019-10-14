/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** my_putstr
*/

#include "../include/my.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
    return (0);
}
