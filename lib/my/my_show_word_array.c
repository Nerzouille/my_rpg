/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday08-florian.reynaud
** File description:
** my_show_word_array
*/
#include <unistd.h>

static int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        write(1, &str[i], 1);
    }
}

static void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_show_word_array(char *const *tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}
