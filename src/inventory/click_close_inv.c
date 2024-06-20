/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** click_close_inv.c
*/

#include "../../include/game.h"

void close_when_cross(game_t *game, inventory_t *inventory,
    sfVector2i mouse_pos)
{
    if ((mouse_pos.x > 1195 && mouse_pos.x < 1245) &&
        (mouse_pos.y > 725 && mouse_pos.y < 770) &&
        sfClock_getElapsedTime(inventory->slot_pressed_clock).microseconds
        > 200000)
        inventory->is_open = 0;
}

void close_when_cross_1280(game_t *game, inventory_t *inventory,
    sfVector2i mouse_pos)
{
    if ((mouse_pos.x > 875 && mouse_pos.x < 920) &&
        (mouse_pos.y > 540 && mouse_pos.y < 590) &&
        sfClock_getElapsedTime(inventory->slot_pressed_clock).microseconds
        > 200000)
        inventory->is_open = 0;
}
