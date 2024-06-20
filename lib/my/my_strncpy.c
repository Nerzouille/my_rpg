/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-florian.reynaud
** File description:
** my_strncpy
*/
#include <stdio.h>

static int size1(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int size = size1(src);
    char c;

    for (int i = 0; n > 0; i++) {
        c = src[i];
        dest[i] = c;
        n--;
    }
    if (n > size) {
        dest[size] = '\0';
    }
    return dest;
}
