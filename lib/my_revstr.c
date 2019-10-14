/*
** EPITECH PROJECT, 2018
** task03
** File description:
** my_revstr
*/

#include "../include/my.h"

char *my_revstr(char *str)
{
    char loop;
    int len = 0;

    len = my_strlen(str) - 1;
    for (int i = 0; len > i; i += 1) {
        loop = str[i];
        str[i] = str[len];
        str[len] = loop;
        len -= 1;
    }
    return (str);
}
