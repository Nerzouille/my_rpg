/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** xp_bar
*/

#include "../include/my_rpg.h"
#include <SFML/Graphics/Color.h>

xp_bar_t *xp_bar_create(sfVector2f pos, sfVector2f size,
    int xp, int xp_max)
{
    xp_bar_t *xp_bar = malloc(sizeof(xp_bar_t));

    xp_bar->pos = pos;
    xp_bar->size = size;
    xp_bar->xp = xp;
    xp_bar->xp_max = xp_max;
    xp_bar->bar = sfRectangleShape_create();
    xp_bar->bg = sfRectangleShape_create();
    xp_bar->bg_size = (sfVector2f){size.x, size.y};
    sfRectangleShape_setSize(xp_bar->bar, size);
    sfRectangleShape_setSize(xp_bar->bg, xp_bar->bg_size);
    sfRectangleShape_setPosition(xp_bar->bar, pos);
    sfRectangleShape_setPosition(xp_bar->bg, pos);
    sfRectangleShape_setFillColor(xp_bar->bar, sfBlue);
    sfRectangleShape_setFillColor(xp_bar->bg,
    sfColor_fromRGBA(10, 10, 10, 200));
    sfRectangleShape_setOutlineColor(xp_bar->bg, sfWhite);
    sfRectangleShape_setOutlineThickness(xp_bar->bg, 1);
    return xp_bar;
}

void xp_bar_update(xp_bar_t *xp_bar, sfVector2f pos, int xp)
{
    float ratio = (float)xp / xp_bar->xp_max;

    if (ratio < 0)
        ratio = 0;
    xp_bar->xp = xp;
    xp_bar->size = (sfVector2f){xp_bar->bg_size.x *
    ratio, xp_bar->bg_size.y};
    sfRectangleShape_setSize(xp_bar->bar, xp_bar->size);
    sfRectangleShape_setPosition(xp_bar->bar, pos);
    sfRectangleShape_setPosition(xp_bar->bg, pos);
}

void xp_bar_display(xp_bar_t *xp_bar, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, xp_bar->bg, NULL);
    sfRenderWindow_drawRectangleShape(window, xp_bar->bar, NULL);
}

void xp_bar_destroy(xp_bar_t *xp_bar)
{
    sfRectangleShape_destroy(xp_bar->bar);
    sfRectangleShape_destroy(xp_bar->bg);
    free(xp_bar);
}
