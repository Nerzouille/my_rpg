/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday11-florian.reynaud
** File description:
** my_list
*/
#include <stdlib.h>
#include "mylist.h"
#include "my.h"

int my_list_size(linked_list_t const *begin)
{
    int size = 0;
    linked_list_t const *tmp;

    tmp = begin;
    while (tmp != NULL){
        size++;
        tmp = tmp->next;
    }
    return size;
}
