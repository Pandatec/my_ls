/*
** EPITECH PROJECT, 2019
** my_ls.h
** File description:
** my_ls.h
*/

#ifndef MY_LS_H_
# define MY_LS_H_

#define ARGS "lRdrt"
#define SIZE_ARG 5
#define S_IFMT 0170000
#define S_IFSOCK 0140000
#define S_IFLNK 0120000

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include "my.h"

typedef struct arg_s {
    char c;
    int ispresent;
} arg_t;

typedef struct dir_s {
    char *path;
    char *rpath;
    char root;
    char d;
    struct stat stats;
    struct dir_s *next;
    struct dir_s *prev;
} dir_t;

typedef struct rec_t {
    char *path;
    dir_t *fold_cont;
    struct dirent *file;
    DIR *fold;
} rec_t;

typedef struct par_s {
    int nbpath;
    arg_t targ[SIZE_ARG];
    dir_t *tdir;
} par_t;

int swap_chains(dir_t *, dir_t *);
int my_perror(char *, char *);
char *my_strcat_ls(char *, char *);
int lstat(const char *, struct stat *);
ssize_t readlink(const char *, char *, size_t);
int add_dir_to_end_list(par_t *, char *);
int add_file_to_end_list(dir_t *, char *, char *);
int conf_file(dir_t *);
void fill_rec_list(par_t *, rec_t *);
void fill_folder_list(par_t *, DIR *, char *);
int fill_dir_arg(par_t *, char *);
void read_d(par_t *);
void read_d_r(par_t *);
void my_ls_r(par_t *);
void my_ls(par_t *);
int my_strcmp_ls(char *, char *);
int set_present(par_t *, char);
void launch_ls(par_t *);
void free_str(char *);
void conf_dir_to_list(par_t *, char *, dir_t *);
void launch_read_file(dir_t *, par_t *, char *);
void print_that_debf(char, char);
void free_t_dir(dir_t *);
void free_t_dir_main(dir_t *);
void print_file_color(char *, dir_t *);
void print_folder_list_col(char *, dir_t *);
void print_col_symb(char *, char);
void print_color(char *, char);
void print_spaces(dir_t *, int);
void print_symbolics(dir_t *, char);
void print_rights(dir_t *);
void print_time(dir_t *);
int print_blocks(par_t *, dir_t *);
char print_type(dir_t *);
void print_stats(dir_t *, int);
void show_stats(par_t *, dir_t *);
void show_stats_r(par_t *, dir_t *);
void conf_arg(par_t *, char *);
void replace_maj(char *);
void fill_folder_stats(DIR *, par_t *, char *);
void read_folder_list_n(dir_t *);
void read_folder_list_r(dir_t *);
void read_folder_list(dir_t *, par_t *);
void launch_read(par_t *, DIR *, char *);
void my_ls_tri_time(par_t *, dir_t *);
void my_ls_tri(dir_t *);

#endif
