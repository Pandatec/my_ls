/*
** EPITECH PROJECT, 2018
** no_printable
** File description:
** transform caracter no printable in octal
*/

#include "../include/my.h"
#include <stdlib.h>

void convert(int number)
{
    int nb[3];
    int res = 0;
    int i = 0;

    for (; i < 3; i += 1)
        nb[i] = 0;
    for (i = 2; number > 0; i -= 1) {
        res = number % 8;
        number = number / 8;
        nb[i] = res;
    }
    for (i = 0; i < 3; i += 1)
        my_put_nbr(nb[i]);
}

int  no_printable(char *str)
{
    for (int i = 0; str[i]; i +=1) {
        if (str[i] < 32 || str[i] == 127) {
            my_putstr("\\");
            convert(str[i]);
        }
    }
    return (0);
}
