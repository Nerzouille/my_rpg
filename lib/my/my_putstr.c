/*
** EPITECH PROJECT, 2023
** c poll day04
** File description:
** my_putstr
*/
#include <unistd.h>

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        write(1, &str[i], 1);
    }
}
