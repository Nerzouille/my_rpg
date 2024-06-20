/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** obstacle
*/

#include "../../include/obstacle.h"
#include <SFML/Graphics/RectangleShape.h>
#include <stdlib.h>
#include <stdio.h>

obstacle_t *obstacle_create(sfVector2f pos)
{
    obstacle_t *obstacle = malloc(sizeof(obstacle_t));

    obstacle->pos = pos;
    obstacle->sprite = sfRectangleShape_create();
    obstacle->rect = (sfIntRect){pos.x, pos.y, 48, 48};
    sfRectangleShape_setSize(obstacle->sprite, (sfVector2f){48, 48});
    sfRectangleShape_setFillColor(obstacle->sprite, sfRed);
    sfRectangleShape_setPosition(obstacle->sprite, obstacle->pos);
    return obstacle;
}

void obstacle_display(obstacle_t *obstacle, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, obstacle->sprite, NULL);
}

void obstacle_destroy(obstacle_t *obstacle)
{
    sfRectangleShape_destroy(obstacle->sprite);
    free(obstacle);
}
