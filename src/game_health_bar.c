/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** game_health_bar
*/

#include "../include/my_rpg.h"
#include "../include/utils.h"
#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>

static sfVector2f offset_pos(sfVector2f pos, game_t *game)
{
    sfVector2f size = sfView_getSize(game->cam->view);

    pos.x = pos.x - (size.x / 2) + 20;
    pos.y = pos.y + (size.y / 2) - 60;
    return pos;
}

health_bar_t *game_health_bar_create(game_t *game)
{
    health_bar_t *health_bar = NULL;
    sfVector2f pos = sfView_getCenter(game->cam->view);
    sfVector2f size = {200, 20};

    pos = offset_pos(pos, game);
    health_bar = health_bar_create(pos, size, game->player->health,
        game->player->health_max);
    return health_bar;
}

void game_health_bar_update(game_t *game)
{
    sfVector2f pos = sfView_getCenter(game->cam->view);

    pos = offset_pos(pos, game);
    health_bar_update(game->health_bar, pos, game->player->health,
        game->player->health_max);
}
