/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday11-florian.reynaud
** File description:
** my_concat_list
*/
#include <stdlib.h>
#include "mylist.h"
#include "my.h"

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    linked_list_t *current = *begin1;
    linked_list_t *prev = NULL;

    while (current != NULL){
        prev = current;
        current = current->next;
    }
    prev->next = begin2;
    return;
}
