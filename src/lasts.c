/*
** EPITECH PROJECT, 2019
** lasts.c
** File description:
** gestion dir
*/

#include "../include/my_ls.h"
#include "../include/my.h"

void free_t_dir_main(dir_t *tdir)
{
    dir_t *tmp;
    dir_t *tmp2;

    free_str(tdir->path);
    tmp = tdir->next;
    while (tmp != tdir && tmp) {
        tmp2 = tmp->next;
        if (tmp != NULL)
            free(tmp);
        tmp = tmp2;
    }
    if (tdir != NULL)
        free(tdir);
}

void conf_dir_to_list(par_t *tpar, char *str, dir_t *elem)
{
    elem->path = str;
    elem->rpath = str;
    elem->root = '0';
    elem->next = tpar->tdir;
    elem->prev = tpar->tdir->prev;
    tpar->tdir->prev->next = elem;
    tpar->tdir->prev = elem;
}
