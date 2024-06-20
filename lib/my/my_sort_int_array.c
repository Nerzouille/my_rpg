/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday04-florian.reynaud
** File description:
** my_sort_int_array
*/
#include <unistd.h>

static void my_swap3(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}

static void sort_step(int *array, int size)
{
    for (int j = 0; j < size - 1; j++){
        if (array[j] > array[j + 1]){
                my_swap3(&array[j], &array[j + 1]);
        }
    }
}

void my_sort_int_array(int *array, int size)
{
    int size_step = size;

    for (int i = 0; i < size; i++){
        sort_step(array, size_step);
        size_step = size - i;
    }
}
