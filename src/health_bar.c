/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** health_bar
*/

#include "../include/my_rpg.h"
#include "../include/utils.h"
#include <SFML/System/Vector2.h>

health_bar_t *health_bar_create(sfVector2f pos, sfVector2f size,
    int health, int health_max)
{
    health_bar_t *health_bar = malloc(sizeof(health_bar_t));

    health_bar->pos = pos;
    health_bar->size = size;
    health_bar->health = health;
    health_bar->health_max = health_max;
    health_bar->bar = sfRectangleShape_create();
    health_bar->bg = sfRectangleShape_create();
    health_bar->bg_size = (sfVector2f){size.x, size.y};
    sfRectangleShape_setSize(health_bar->bar, size);
    sfRectangleShape_setSize(health_bar->bg, health_bar->bg_size);
    sfRectangleShape_setPosition(health_bar->bar, pos);
    sfRectangleShape_setPosition(health_bar->bg, pos);
    sfRectangleShape_setFillColor(health_bar->bar, sfGreen);
    sfRectangleShape_setFillColor(health_bar->bg, sfRed);
    return health_bar;
}

void health_bar_update(health_bar_t *health_bar, sfVector2f pos, int health,
    int health_max)
{
    float ratio;

    health_bar->health_max = health_max;
    ratio = (float)health / health_bar->health_max;
    if (ratio < 0)
        ratio = 0;
    health_bar->health = health;
    health_bar->size = (sfVector2f){health_bar->bg_size.x *
    ratio, health_bar->bg_size.y};
    sfRectangleShape_setSize(health_bar->bar, health_bar->size);
    sfRectangleShape_setPosition(health_bar->bar, pos);
    sfRectangleShape_setPosition(health_bar->bg, pos);
}

void health_bar_display(health_bar_t *health_bar, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, health_bar->bg, NULL);
    sfRenderWindow_drawRectangleShape(window, health_bar->bar, NULL);
}

void health_bar_destroy(health_bar_t *health_bar)
{
    sfRectangleShape_destroy(health_bar->bar);
    sfRectangleShape_destroy(health_bar->bg);
    free(health_bar);
}
