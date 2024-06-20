/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-florian.reynaud
** File description:
** mylist
*/

#ifndef MYLIST_H_
    #define MYLIST_H_

typedef struct linked_list_s {
    void *data;
    struct linked_list_s *next;
}linked_list_t;

void push_to_list(linked_list_t **begin, void *data);
void display_list(linked_list_t *begin, void (*disp_fct)());
void delete_in_list(linked_list_t **begin, void const *ref, int (*cmp_fct)());
void delete_node(linked_list_t **begin,
    linked_list_t *prev, linked_list_t *next);
#endif /* !MYLIST_H_ */
