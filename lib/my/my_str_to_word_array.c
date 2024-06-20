/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday08-florian.reynaud
** File description:
** my_str_to_word_array
*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static int my_char_isalpha(char c)
{
    if (c >= 'A' && c <= 'Z'){
        return (1);
    }
    if (c >= 'a' && c <= 'z'){
        return (1);
    }
    return (0);
}

static int my_char_isnum(char c)
{
    if (c >= '0' && c <= '9'){
        return (1);
    }
    return (0);
}

static void count_word_step(char const *str, int i, int *nb, int *in_word)
{
    if (!*in_word && (my_char_isalpha(str[i]) || my_char_isnum(str[i]))) {
        *in_word = 1;
        *nb += 1;
    } else if (!my_char_isalpha(str[i]) && !my_char_isnum(str[i])) {
        *in_word = 0;
    }
    return;
}

static int count_word(char const *str)
{
    int nb = 0;
    int i = 0;
    int in_word = 0;

    while (str[i] != '\0'){
        count_word_step(str, i, &nb, &in_word);
        i++;
    }
    return nb;
}

static int count_char_in_word(char const *str, int i)
{
    int nb = 0;

    while (my_char_isalpha(str[i]) || my_char_isnum(str[i])){
        nb++;
        i++;
    }
    return nb;
}

static char **else_step(char **tab, int *tab_i, int *tab_j, int size)
{
    tab[*tab_i][*tab_j] = '\0';
    if (tab[*tab_i][0] == '\0'){
        tab[*tab_i] = malloc(sizeof(char) * size + 1);
    } else {
        *tab_i = *tab_i + 1;
        *tab_j = 0;
        tab[*tab_i] = malloc(sizeof(char) * size + 1);
    }
    return tab;
}

static char **my_str_to_word_array2(char const *str, char **tab)
{
    int tab_i = 0;
    int tab_j = 0;
    int i = 0;

    while (str[i] != '\0'){
        if ((my_char_isalpha(str[i]) || my_char_isnum(str[i]))){
            tab[tab_i][tab_j] = str[i];
            tab_j++;
        } else {
            else_step(tab, &tab_i, &tab_j, count_char_in_word(str, i + 1));
        }
        i++;
    }
    if (my_char_isalpha(str[i - 1]) || my_char_isnum(str[i - 1])){
        tab[tab_i][tab_j] = '\0';
        tab[tab_i + 1] = NULL;
    } else {
        tab[tab_i] = NULL;
    }
    return tab;
}

char **my_str_to_word_array(char const *str)
{
    char **tab;

    if (count_word(str) == 0){
        tab = malloc(sizeof(char *));
        tab[0] = NULL;
    } else {
        tab = malloc(sizeof(char *) * (count_word(str) + 1));
        tab[0] = malloc(sizeof(char) * (count_char_in_word(str, 0)) + 1);
        tab = my_str_to_word_array2(str, tab);
    }
    return tab;
}
