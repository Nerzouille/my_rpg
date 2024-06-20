/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-florian.reynaud
** File description:
** my_nbr_to_str
*/

#include "my.h"
#include <stdlib.h>

static int nbr_length(unsigned int nbr)
{
    int count = 0;

    while (nbr > 0){
        count++;
        nbr /= 10;
    }
    return count;
}

char *my_nbr_to_str(unsigned int nbr)
{
    int size = nbr_length(nbr);
    char *str = malloc(size + 1);
    char c = '0';

    str[size] = '\0';
    while (nbr > 0){
        size--;
        str[size] = c + (nbr % 10);
        nbr /= 10;
    }
    return str;
}
