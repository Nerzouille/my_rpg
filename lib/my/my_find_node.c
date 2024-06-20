/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday11-florian.reynaud
** File description:
** my_find_node
*/
#include <stdlib.h>
#include "mylist.h"
#include "my.h"

linked_list_t *my_find_node(linked_list_t *begin,
    void const *data_ref, int (*cmp)())
{
    linked_list_t *tmp;

    tmp = begin;
    while (tmp != NULL){
        if ((*cmp)(tmp->data, data_ref) == 0){
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}
