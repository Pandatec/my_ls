/*
** EPITECH PROJECT, 2018
** my_put_unsigned_nbr
** File description:
** print unsigned int
*/

#include <stdlib.h>
#include "../include/my.h"

char *my_put_nbr_unsigned(unsigned int nb, char const *base)
{
    int len_base = my_strlen(base);
    char *result = malloc(sizeof(char) * (len_base + 2));

    if (result == NULL)
        return (NULL);
    if (nb == 0) {
        return (0);
    } else {
        for (int i = 0; nb != 0; i += 1) {
            result[i] = base[nb % len_base];
            nb = nb / len_base;
        }
        result = my_revstr(result);
        my_putstr(result);
    }
    free(result);
    return (0);
}
