/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-bsmyls-florian.reynaud
** File description:
** my_str_add
*/
#include "my.h"

char *my_str_add(char *dest, char c)
{
    char *temp = dest;
    int len;

    len = my_strlen(temp);
    dest[len] = c;
    dest[len + 1] = '\0';
    return dest;
}
