/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** render_inventory.c
*/

#include "../../include/my_rpg.h"


void render_inventory(game_t *game, inventory_t *inventory,
    sfRenderWindow *window)
{
    sfVector2f scale_inv = {0.75, 0.75};
    sfVector2f pos_inv = {game->player->pos.x - 200,
        game->player->pos.y - 125};
    sfIntRect rect_inv = {0, 0, 626, 352};

    if (inventory->is_open) {
        sfSprite_setTexture(inventory->inventory_sprite,
            inventory->inventory_texture, sfTrue);
        sfSprite_setScale(inventory->inventory_sprite, scale_inv);
        sfSprite_setPosition(inventory->inventory_sprite, pos_inv);
        sfSprite_setTextureRect(inventory->inventory_sprite, rect_inv);
        sfRenderWindow_drawSprite(window, inventory->inventory_sprite, NULL);
    }
}
