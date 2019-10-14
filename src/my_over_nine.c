/*
** EPITECH PROJECT, 2019
** my_over_nine.c
** File description:
** print special caracter
*/

#include "../include/my_ls.h"
#include "../include/my.h"

void launch_read_file(dir_t *file, par_t *tpar, char *path)
{
    if (tpar->targ[0].ispresent == 1)
        print_stats(file, file->stats.st_size);
    else
        my_printf("%s\n", path);
}

int print_blocks(par_t *tpar, dir_t *file)
{
    dir_t *tmp = file;
    int block = 0;
    int max = 0;

    while ((tmp = tmp->next) && tmp->root != '1') {
        max = ((tmp->stats.st_size > max) ? tmp->stats.st_size : max);
        block += tmp->stats.st_blocks;
    }
    if (block && tpar->targ[2].ispresent == 0)
        my_printf("total %d\n", block / 2);
    return (max);
}

void print_col_symb(char *str, char c)
{
    if (c == 'l')
        my_printf(" %c[32m%s%c[0m\n", 27, str, 27);
}

void print_color(char *str, char c)
{
    if (c == 'd')
        my_printf(" %c[34;1m%s%c[0m\n", 27, str, 27);
    else if (c == 'l')
        my_printf(" %c[36m%s%c[0m ->", 27, str, 27);
    else
        my_printf(" %s\n", str);
}

void print_symbolics(dir_t *file, char c)
{
    ssize_t r;
    char *link;

    if (c != 'l')
        print_color(file->path, c);
    else {
        if ((link = malloc(file->stats.st_size + 1)) == NULL)
            return ;
        if ((r = readlink(file->rpath, link, file->stats.st_size + 1)) == -1) {
            perror(" my_ls");
            my_putchar('\n');
            return ;
        }
        link[r] = 0;
        print_color(file->path, c);
        print_col_symb(link, c);
        if (link != NULL)
            free(link);
    }
}
