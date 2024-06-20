/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday08-florian.reynaud
** File description:
** my_strdup
*/
#include <stdlib.h>

static int my_strlen89(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strdup(char const *src)
{
    char *dest;
    int len = my_strlen89(src);
    int i = 0;

    dest = malloc(len + 1);
    while (src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
