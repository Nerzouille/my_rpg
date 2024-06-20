/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** shoot
*/
#include "../../include/my_rpg.h"

void player_handle_shoot(player_t *player, game_t *game)
{
    if (player->gun == NULL)
        return;
    gun_shoot(player->gun, game);
}
