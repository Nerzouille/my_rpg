/*
** EPITECH PROJECT, 2023
** source
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    int x = 1;
    int square_root = 0;

    while (nb > 0){
        nb -= x;
        square_root++;
        x += 2;
    }
    if (nb < 0){
        return (0);
    } else {
        return (square_root);
    }
}
