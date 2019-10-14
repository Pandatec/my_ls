/*
** EPITECH PROJECT, 2019
** my_pustr_error
** File description:
** my_put_str_error
*/

#include "../include/my.h"
#include <unistd.h>

void my_putchar_err(char c)
{
    write(2, &c, 1);
}

void my_putstr_err(char const *str)
{
    for (int i = 0; str[i]; i += 1)
        my_putchar(str[i]);
}
