/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** bullet_list
*/

#include "../../include/my_rpg.h"

bullet_list_t *destroy_bullet_in_list(bullet_list_t *list, bullet_t *bullet)
{
    bullet_list_t *current = list;
    bullet_list_t *previous = NULL;

    while (current != NULL && current->bullet != bullet) {
        previous = current;
        current = current->next;
    }
    if (current == NULL)
        return list;
    if (previous == NULL)
        list = current->next;
    else
        previous->next = current->next;
    free(current->bullet);
    free(current);
    return list;
}

bullet_list_t *add_bullet_to_bullet_list(bullet_list_t *list, bullet_t *bullet)
{
    bullet_list_t *new_node;

    if (bullet == NULL)
        return list;
    new_node = malloc(sizeof(bullet_list_t));
    new_node->bullet = bullet;
    new_node->next = list;
    return new_node;
}

bullet_list_t *update_bullet_list(bullet_list_t *list)
{
    bullet_list_t *current = list;
    bullet_list_t *next;

    while (current != NULL) {
        next = current->next;
        bullet_update(current->bullet);
        if (current->bullet->destroy == 1)
            list = destroy_bullet_in_list(list, current->bullet);
        current = next;
    }
    return list;
}

void display_bullet_list(bullet_list_t *list, sfRenderWindow *window)
{
    bullet_list_t *current = list;

    while (current != NULL) {
        bullet_display(current->bullet, window);
        current = current->next;
    }
}

void destroy_bullet_list(bullet_list_t *list)
{
    bullet_list_t *current = list;
    bullet_list_t *temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        bullet_destroy(temp->bullet);
        free(temp);
    }
}
