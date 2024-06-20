/*
** EPITECH PROJECT, 2023
** source
** File description:
** my_put_nbr
*/
#include <unistd.h>

static void print_number(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    char c = '0';

    if (nb < 0){
        write(1, "-", 1);
        nb = nb * -1;
    }
    while (nb % 10 != 0){
        nb--;
        c++;
    }
    nb /= 10;
    if (nb != 0){
        my_put_nbr(nb);
    }
    write(1, &c, 1);
    return (0);
}
