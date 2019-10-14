/*
** EPITECH PROJECT, 2019
** my_ls_tri.c
** File description:
** do a tri for the ls
*/

#include "../include/my_ls.h"
#include "../include/my.h"

void print_spaces(dir_t *file, int max)
{
    long power = 10;

    while (power < max)
        power *= 10;
    power /= 10;
    while (power > file->stats.st_size && power > 1) {
        my_putchar(' ');
        power /= 10;
    }
}

void print_stats(dir_t *file, int max)
{
    struct passwd *ps;
    struct group *gr;
    char c;

    if ((ps = getpwuid(file->stats.st_uid)) == NULL) {
        perror("\nmy_ls");
        return ;
    } else if ((gr = getgrgid(file->stats.st_gid)) == NULL) {
        perror("\nmy_ls");
        return ;
    }
    c = print_type(file);
    print_rights(file);
    my_printf(" %d %s %s ", file->stats.st_nlink, ps->pw_name, gr->gr_name);
    print_spaces(file, max);
    my_printf("%d ", file->stats.st_size);
    print_time(file);
    print_symbolics(file, c);
}

int my_swap_chains(dir_t *tmp, dir_t *tmp2)
{
    tmp->prev->next = tmp2;
    tmp2->next->prev = tmp;
    tmp2->prev = tmp->prev;
    tmp->next = tmp2->next;
    tmp2->next = tmp;
    tmp->prev = tmp2;
    return (0);
}

void my_ls_tri(dir_t *tdir)
{
    dir_t *tmp = tdir;
    dir_t *tmp2;
    int tri = 0;

    if (tmp->next->root == '1')
        return ;
    while (tri == 0 || ((tmp = tmp->next) && tmp->next->root != '1')) {
        tri = 1;
        if (my_strcmp_ls(tmp->path, tmp->next->path) > 0 &&
            tmp->next->root != '1' && tmp->root != '1') {
            tmp2 = tmp->next;
            tri = my_swap_chains(tmp, tmp2);
            tmp = tdir;
        }
    }
}

void my_ls_tri_time(par_t *tpar, dir_t *tdir)
{
    dir_t *tmp = tdir;
    dir_t *tmp2;
    int tri = 0;

    if (tpar->targ[4].ispresent == 1) {
        if (tmp->next->root == '1')
            return ;
        while (tri == 0 || ((tmp = tmp->next) && tmp->next->root != '1')) {
            tri = 1;
            if (tmp->next->root != '1' && tmp->root != '1' &&
                tmp->stats.st_mtime < tmp->next->stats.st_mtime) {
                tmp2 = tmp->next;
                tri = my_swap_chains(tmp, tmp2);
                tmp = tdir;
            }
        }
    }
}
