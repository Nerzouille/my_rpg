/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday11-florian.reynaud
** File description:
** my_delete_nodes
*/
#include <stdlib.h>
#include "mylist.h"
#include "my.h"

static int my_delete_nodes_exception(linked_list_t **begin,
    linked_list_t *prev, linked_list_t *next)
{
    if (prev == NULL){
        *begin = next;
    } else {
        prev->next = next;
    }
}

int my_delete_nodes(linked_list_t **begin, void const *data_ref,
    int(*cmp)())
{
    linked_list_t *current = *begin;
    linked_list_t *next;
    linked_list_t *prev = NULL;

    while (current != NULL){
        next = current->next;
        if ((*cmp)(current->data, data_ref) == 0){
            my_delete_nodes_exception(begin, prev, next);
        } else {
            prev = current;
        }
        current = next;
    }
    return 0;
}
