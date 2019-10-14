/*
** EPITECH PROJECT, 2019
** my_ls_option.c
** File description:
** all the option of my_ls
*/

#include "../include/my.h"
#include "../include/my_ls.h"

void my_ls(par_t *tpar)
{
    DIR *fold;
    dir_t *tmp = tpar->tdir;

    while ((tmp = tmp->next) && tmp->root != '1') {
        print_that_debf(tmp->prev->root, tmp->next->root);
        if ((fold = opendir((const char *)tmp->path)) != NULL) {
            if (tpar->nbpath > 1)
                my_printf("%s:\n", tmp->path);
            launch_read(tpar, fold, tmp->path);
        } else
            launch_read_file(tmp, tpar, tmp->path);
    }
}

void my_ls_r(par_t *tpar)
{
    DIR *fold;
    dir_t *tmp = tpar->tdir;

    while ((tmp = tmp->prev) && tmp->root != '1') {
        print_that_debf(tmp->next->root, tmp->prev->root);
        if ((fold = opendir((const char *)tmp->path)) != NULL) {
            if (tpar->nbpath > 1)
                my_printf("%s:\n", tmp->path);
            launch_read(tpar, fold, tmp->path);
        } else
            launch_read_file(tmp, tpar, tmp->path);
    }
}

void replace_maj(char *str)
{
    int i = 0;

    while (str[i]) {
        str[i] -= (str[i] >= 'A' && str[i] <= 'Z') ? 'A' - 'a' : 0;
        i += 1;
    }
}

int my_strcmp_ls(char *str, char *str2)
{
    int i = 0;
    int val;
    char *cmp;
    char *cmp2;

    if ((cmp = my_strdup(str)) == NULL || (cmp2 = my_strdup(str2)) == NULL)
        return (0);
    replace_maj(cmp);
    replace_maj(cmp2);
    while (cmp[i] && cmp2[i] && cmp[i] == cmp2[i])
        i += 1;
    val = cmp[i] - cmp2[i];
    free(cmp);
    free(cmp2);
    return (val);
}

int add_dir_to_end_list(par_t *tpar, char *path)
{
    dir_t *elem;
    dir_t *tmp = tpar->tdir->next;

    while (tmp->root != '1') {
        if (my_strcmp(tmp->path, path) == 0)
            return (0);
        tmp = tmp->next;
    }
    if ((elem = malloc(sizeof(dir_t))) == NULL)
        return (1);
    tpar->nbpath += 1;
    if (lstat((const char *)path, &elem->stats) == -1) {
        free(elem);
        return (my_perror("my_ls: cannot access ", path));
    } else
        conf_dir_to_list(tpar, path, elem);
    return (0);
}
