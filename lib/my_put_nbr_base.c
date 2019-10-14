/*
** EPITECH PROJECT, 2018
** my_put_nbr_base
** File description:
** my_put_nbr_base
*/

#include <stdlib.h>
#include "../include/my.h"

char into_else(char *result, char const *base, int len_base, int nb)
{
    for (int i = 0; nb != 0; i += 1) {
        result[i] = base[nb % len_base];
        nb = nb / len_base;
    }
    result = my_revstr(result);
    my_putstr(result);
    return (0);
}

char *my_put_nbr_base(int nb, char const *base)
{
    int len_base = my_strlen(base);
    char *result = malloc(sizeof(char) * (len_base + 2));

    if (result == NULL)
        exit (84);
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb == 0) {
        return (0);
    } else {
        into_else(result, base, len_base, nb);
    }
    free(result);
    return (0);
}
