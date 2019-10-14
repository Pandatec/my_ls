/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** recode printf
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../include/my.h"

char *other(va_list list, char *str, int count)
{
    switch (str[count]) {
    case 'S':
        no_printable(va_arg(list, char *));
        break;
    }
    return (str);
}

char *bi_oct_hexa(va_list list, char *str, int count)
{
    switch (str[count]) {
    case 'x':
        my_put_nbr_base(va_arg(list, int), "0123456789abcdef");
        break;
    case 'X':
        my_put_nbr_base(va_arg(list, int), "0123456789ABCDEF");
        break;
    case 'b':
        my_put_nbr_base(va_arg(list, int), "01");
        break;
    case 'o':
        my_put_nbr_base(va_arg(list, int), "01234567");
        break;
    case 'p':
        my_putstr("0x");
        my_put_nbr_base(va_arg(list, long int), "0123456789abcdef");
        break;
    }
    return (str);
}

char *str_nb_char(va_list list, char *str, int count)
{
    switch (str[count]) {
    case 's':
        my_putstr(va_arg(list, char *));
        break;
    case 'c':
        my_putchar(va_arg(list, int));
        break;
    case 'i':
    case 'd':
        my_put_nbr(va_arg(list, int));
        break;
    case 'u':
        my_put_nbr_unsigned(va_arg(list, unsigned int), "0123456789");
        break;
    case '%':
        my_putchar('%');
        break;
    }
    return (str);
}

int my_printf(char *str, ...)
{
    va_list list;

    va_start(list, str);
    for (int count = 0; str[count]; count += 1) {
        if (str[count] == '%') {
            count += 1;
            str_nb_char(list, str, count);
            bi_oct_hexa(list, str, count);
        } else
            my_putchar(str[count]);
    }
    va_end(list);
    return (0);
}
