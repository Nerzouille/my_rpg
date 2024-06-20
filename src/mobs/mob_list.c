/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** mob_list
*/

#include "../../include/my_rpg.h"
#include <stdlib.h>
#include <stdio.h>

mob_list_t *add_mob_to_mob_list(mob_list_t *list,
    mob_t *mob)
{
    mob_list_t *new_node;

    if (mob == NULL)
        return list;
    new_node = malloc(sizeof(mob_list_t));
    new_node->mob = mob;
    new_node->next = list;
    return new_node;
}

void mob_list_display(mob_list_t *list, sfRenderWindow *window)
{
    mob_list_t *tmp = list;

    while (tmp != NULL){
        mob_display(tmp->mob, window);
        tmp = tmp->next;
    }
}

void mob_list_destroy(mob_list_t *list)
{
    mob_list_t *tmp = list;
    mob_list_t *next;

    while (tmp != NULL){
        next = tmp->next;
        mob_destroy(tmp->mob);
        free(tmp);
        tmp = next;
    }
}

static int mob_list_remove(mob_list_t **list, mob_list_t **current,
    mob_list_t **prev, mob_list_t **next)
{
    int destroy = 0;

    if (!((*current)->mob->alive)){
        if (*prev != NULL) {
            (*prev)->next = *next;
        } else {
            *list = *next;
        }
        mob_destroy((*current)->mob);
        free(*current);
        destroy = 1;
    } else {
        *prev = *current;
    }
    *current = *next;
    return destroy;
}

mob_list_t *mob_list_update(mob_list_t *list, sfRenderWindow *window,
    game_t *game)
{
    mob_list_t *current = list;
    mob_list_t *prev = NULL;
    mob_list_t *next = NULL;

    while (current != NULL){
        next = current->next;
        mob_update(current->mob, window, game);
        if (mob_list_remove(&list, &current, &prev, &next))
            game->player->xp += XP_GAIN;
    }
    return list;
}
