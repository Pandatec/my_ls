/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** my_strdup.c
*/

#include <stdlib.h>
#include "../include/my.h"

char *my_strdup(char *str)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * my_strlen(str) + 1);

    if (dest == NULL)
        return (NULL);
    while (str[i]) {
        dest[i] = str[i];
        i += 1;
    }
    dest[i] = 0;
    return (dest);
}
