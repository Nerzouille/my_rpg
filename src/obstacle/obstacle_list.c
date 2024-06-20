/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** obstacle_list
*/

#include "../../include/obstacle.h"
#include <stdio.h>
#include <stdlib.h>

obstacle_list_t *add_obstacle_to_obstacle_list(obstacle_list_t *list,
    obstacle_t *obstacle)
{
    obstacle_list_t *new_node;

    if (obstacle == NULL)
        return list;
    new_node = malloc(sizeof(obstacle_list_t));
    new_node->obstacle = obstacle;
    new_node->next = list;
    return new_node;
}

void obstacle_list_display(obstacle_list_t *list, sfRenderWindow *window)
{
    obstacle_list_t *tmp = list;

    while (tmp != NULL){
        obstacle_display(tmp->obstacle, window);
        tmp = tmp->next;
    }
}

void obstacle_list_destroy(obstacle_list_t *list)
{
    obstacle_list_t *tmp = list;
    obstacle_list_t *next;

    while (tmp != NULL){
        next = tmp->next;
        obstacle_destroy(tmp->obstacle);
        free(tmp);
        tmp = next;
    }
}

void obstacle_list_remove(obstacle_list_t *list, obstacle_t *obstacle)
{
    obstacle_list_t *tmp = list;
    obstacle_list_t *prev = list;

    while (tmp != NULL){
        if (tmp->obstacle == obstacle){
            prev->next = tmp->next;
            obstacle_destroy(tmp->obstacle);
            free(tmp);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}
