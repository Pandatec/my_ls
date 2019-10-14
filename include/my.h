/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

int my_printf(char *, ...);
void my_putchar(char);
int my_put_nbr(int);
int my_putstr(char const *);
char *my_put_nbr_unsigned(unsigned int, char const *);
char *my_put_nbr_base(int ,char const *);
int my_strlen(char const *);
char *my_revstr(char *);
int my_put_nbr_long(long int);
int no_printable(char *);
void my_putstr_err(char const *);
void my_putchar_err(char);
int my_strcmp(char const *, char const *);
char *my_strdup(char *);

#endif
