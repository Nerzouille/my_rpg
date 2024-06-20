/*
** EPITECH PROJECT, 2023
** source
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    int power;

    if (p == 0){
        return (1);
    }
    if (p < 0){
        return (0);
    }
    power = nb * my_compute_power_rec(nb, p - 1);
    return (power);
}
