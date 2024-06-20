/*
** EPITECH PROJECT, 2023
** source
** File description:
** my_find_prime_sup
*/

static int my_is_prime2(int nb)
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

int my_find_prime_sup(int nb)
{
    if (nb < 0) {
        return (2);
    }
    while (my_is_prime2(nb) == 0){
        nb++;
    }
    return (nb);
}
