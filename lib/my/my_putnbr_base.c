/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-florian.reynaud
** File description:
** my_putnbr_base
*/
#include <unistd.h>
#include <stdio.h>

static int my_strlen12(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_putnbr_base(int nbr, char const *base)
{
    int base_len = my_strlen12(base);
    int unit;
    char unit_char;

    if (nbr == 0){
        return (0);
    }
    unit = nbr % base_len;
    unit_char = base[unit];
    my_putnbr_base(nbr / base_len, base);
    write(1, &unit_char, 1);
    return (0);
}
