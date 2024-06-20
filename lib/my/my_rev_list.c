/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday11-florian.reynaud
** File description:
** my_rev_list
*/
#include <stdlib.h>
#include "mylist.h"
#include "my.h"

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *current = *begin;
    linked_list_t *next;
    linked_list_t *prev = NULL;

    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *begin = prev;
    return;
}
