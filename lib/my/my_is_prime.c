/*
** EPITECH PROJECT, 2023
** source
** File description:
** my_is_prime
*/

int my_is_prime(int nb)
{
    int divider;
    int is_prime = 1;

    if (nb <= 0 || nb == 1) {
        return (0);
    }
    for (divider = 2; divider < nb; divider++) {
        if (nb % divider == 0) {
            is_prime = 0;
        }
    }
    return (is_prime);
}
