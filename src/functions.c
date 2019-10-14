/*
** EPITECH PROJECT, 2019
** function.c
** File description:
** basic fonction
*/

#include "../include/my_ls.h"
#include "../include/my.h"

void show_stats(par_t *tpar, dir_t *fold_cont)
{
    int max = print_blocks(tpar, fold_cont);
    dir_t *tmp = fold_cont->next;

    while (tmp->root != '1') {
        print_stats(tmp, max);
        tmp = tmp->next;
    }
}

void show_stats_r(par_t *tpar, dir_t *fold_cont)
{
    int max = print_blocks(tpar, fold_cont);
    dir_t *tmp = fold_cont->prev;

    while (tmp->root != '1') {
        print_stats(tmp, max);
        tmp = tmp->prev;
    }
}

void fill_dir_files(par_t *tpar, rec_t *trec)
{
    if ((trec->file = readdir(trec->fold)) == NULL) {
        perror("\nmy_ls");
        return ;
    }
    if ((trec->fold_cont = malloc(sizeof(dir_t))) == NULL)
        return ;
    conf_file(trec->fold_cont);
    while (trec->file != NULL) {
        if (trec->file->d_name[0] != '.')
            add_file_to_end_list(trec->fold_cont, trec->file->d_name,
                                 trec->path);
        trec->file = readdir(trec->fold);
    }
    my_ls_tri(trec->fold_cont);
    my_ls_tri_time(tpar, trec->fold_cont);
    if (tpar->targ[3].ispresent == 0)
        show_stats(tpar, trec->fold_cont);
    else
        show_stats_r(tpar, trec->fold_cont);
}

void fill_folder_stats(DIR *fold, par_t *tpar, char *path)
{
    rec_t trec;
    char *nextpath;

    trec.path = path;
    trec.fold = fold;
    fill_dir_files(tpar, &trec);
    if (tpar->targ[1].ispresent == 1)
        while ((trec.fold_cont = trec.fold_cont->next) &&
               trec.fold_cont->root != '1') {
            if (trec.fold_cont->d == 'd')
            {
                my_putchar('\n');
                nextpath = my_strcat_ls(path, trec.fold_cont->path);
                my_printf("%s:\n", nextpath);
                fill_folder_stats(opendir(nextpath), tpar, nextpath);
                free_str(nextpath);
            }
        }
    closedir(trec.fold);
    free_t_dir(trec.fold_cont);
}

void launch_read(par_t *tpar, DIR *fold, char *path)
{
    if (tpar->targ[0].ispresent == 0)
        fill_folder_list(tpar, fold, path);
    else
        if (tpar->targ[2].ispresent == 0) {
            if (tpar->targ[1].ispresent == 1)
                my_printf("%s:\n", path);
            fill_folder_stats(fold, tpar, path);
        }
        else
            if (tpar->targ[3].ispresent == 0)
                show_stats(tpar, tpar->tdir);
            else
                show_stats_r(tpar, tpar->tdir);
}
