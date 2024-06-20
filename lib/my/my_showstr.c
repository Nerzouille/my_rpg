/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-florian.reynaud
** File description:
** my_showstr
*/
#include <unistd.h>

static int my_strlen6(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

static int my_putnbr_base2(int nbr, char const *base, int nb_print)
{
    int base_len = my_strlen6(base);
    int unit;
    char unit_char;

    if (nbr == 0){
        if (nb_print == 2){
            write(1, &base[0], 1);
        }
        return (0);
    }
    unit = nbr % base_len;
    unit_char = base[unit];
    my_putnbr_base2(nbr / base_len, base, nb_print + 1);
    write(1, &unit_char, 1);
    return (0);
}

static int char_isprintable2(char c)
{
    if ((c >= 32 && c <= 126)){
        return (1);
    }
    return (0);
}

int my_showstr(char const *str)
{
    int i = 0;
    char *base = "0123456789abcdef";

    while (str[i] != '\0') {
        if (char_isprintable2(str[i])){
            write(1, &str[i], 1);
        } else {
            write(1, "\\", 1);
            my_putnbr_base2(str[i], base, 1);
        }
        i++;
    }
    return (0);
}
