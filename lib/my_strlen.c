/*
** EPITECH PROJECT, 2018
** task03
** File description:
** task03
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int counts = 0;

    while (str[counts] != '\0') {
        counts = counts + 1;
    }
    return (counts);
}
