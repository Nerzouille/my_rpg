/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday06-florian.reynaud
** File description:
** my_getnbr_base
*/
#include <unistd.h>
#include <stdio.h>

static int my_strlen13(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

static int operator_detector(char c)
{
    if (c == '-' || c == '+'){
        return (1);
    }
    return (0);
}

static int my_compute_power_it(int nb, int p)
{
    int power = nb;

    if (p == 0){
        return (1);
    }
    if (p < 0){
        return (0);
    }
    p --;
    while (p > 0){
        power *= nb;
        p--;
    }
    return (power);
}

static void test_neg(int i, char const *str, int *neg_multiplier)
{
    if (str[i] == '-'){
        *neg_multiplier *= -1;
    }
}

static void handle_operator(char const *str, int *i, int *neg_multi)
{
    while (operator_detector(str[*i])){
        test_neg(*i, str, neg_multi);
        *i += 1;
    }
}

static int find_inex_charchter_in_string(char const *str, char c)
{
    int i = 0;

    while (str[i] != c){
        i++;
    }
    return (i);
}

int my_getnbr_base(char const *str, char const *base)
{
    int i = 0;
    int nbr = 0;
    int base_len = my_strlen13(base);
    int unit;
    int multiplier;
    int neg_multiplier = 1;
    int power = 0;

    if (base[0] == '\0'){
        return (0);
    }
    handle_operator(str, &i, &neg_multiplier);
    while (str[i] != '\0'){
        unit = find_inex_charchter_in_string(base, str[i]);
        multiplier = my_compute_power_it(base_len, power);
        nbr += unit * multiplier;
        i++;
        power++;
    }
    return (nbr * neg_multiplier);
}
