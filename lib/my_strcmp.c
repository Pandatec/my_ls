/*
** EPITECH PROJECT, 2018
** task05
** File description:
** my_strcmp
*/

#include "../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int issues = 0;

    while (s1[issues] != '\0' && s2[issues] != '\0') {
        if (s1[issues] != s2[issues])
            return (s1[issues] - s2[issues]);
        issues = issues + 1;
    }
    return (issues);
}
