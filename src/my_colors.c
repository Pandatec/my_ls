/*
** EPITECH PROJECT, 2019
** my_colors.c
** File description:
** bonus of color
*/

#include "../include/my.h"
#include "../include/my_ls.h"

char *my_strcat_ls(char *str, char *str2)
{
    char *tmp = malloc(sizeof(char) * (my_strlen(str) + my_strlen(str2) + 2));
    int i = 0;
    int j = 0;

    if (tmp == NULL)
        return (NULL);
    while (str[i]) {
        tmp[i] = str[i];
        i += 1;
    }
    if (tmp[i - 1] != '/')
        tmp[i++] = '/';
    while (str2[j])
        tmp[i++] = str2[j++];
    tmp[i] = 0;
    return (tmp);
}

void print_folder_list_col(char *str, dir_t *tdir)
{
    if (S_ISDIR(tdir->stats.st_mode))
        my_printf("%c[1;34m%s%c[0m", 27, str, 27);
    else if ((tdir->stats.st_mode & S_IFMT) == S_IFLNK)
        my_printf("%c[36m%s%c[0m", 27, str, 27);
    else
        my_printf("%s", str);
}

void read_folder_list_n(dir_t *tmp)
{
    while (tmp->root != '1') {
        print_folder_list_col(tmp->path, tmp);
        if (tmp->next->root != 1)
            my_printf("\n");
        tmp = tmp->next;
    }
}

void read_folder_list_r(dir_t *tmp)
{
    while (tmp->root != '1') {
        print_folder_list_col(tmp->path, tmp);
        if (tmp->prev->root != 1)
            my_printf("\n");
        tmp = tmp->prev;
    }
}

void read_folder_list(dir_t *tdir, par_t *tpar)
{
    dir_t *tmp;

    tmp = (tpar->targ[3].ispresent == 0) ? tdir->next : tdir->prev;
    if (tpar->targ[3].ispresent == 0)
        read_folder_list_n(tmp);
    else
        read_folder_list_r(tmp);
}
