/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-bsmyls-florian.reynaud
** File description:
** my_putstr_error
*/
#include <unistd.h>

int my_putstr_error(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        write(1, &str[i], 1);
    }
}
