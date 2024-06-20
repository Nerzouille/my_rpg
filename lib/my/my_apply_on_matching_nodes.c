/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday11-florian.reynaud
** File description:
** my_apply_on_matching_nodes
*/
#include <stdlib.h>
#include "mylist.h"
#include "my.h"

int my_apply_on_matching_nodes(linked_list_t *begin, int(*f)(),
    void const *data_ref, int(*cmp)())
{
    linked_list_t *tmp;

    tmp = begin;
    while (tmp != NULL){
        if ((*cmp)(tmp->data, data_ref) == 0){
            (*f)(tmp->data);
        }
        tmp = tmp->next;
    }
    return 0;
}
