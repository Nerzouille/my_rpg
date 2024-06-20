/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** game_xp_bar
*/

#include "../include/my_rpg.h"
#include <SFML/Graphics/View.h>

static sfVector2f offset_pos(sfVector2f pos, game_t *game)
{
    sfVector2f size = sfView_getSize(game->cam->view);

    pos.x = pos.x - (size.x / 2) + 20;
    pos.y = pos.y - (size.y / 2) + 20;
    return pos;
}

xp_bar_t *game_xp_bar_create(game_t *game)
{
    xp_bar_t *xp_bar = NULL;
    sfVector2f pos = sfView_getCenter(game->cam->view);
    sfVector2f size = {sfView_getSize(game->cam->view).x / 2, 20};

    pos = offset_pos(pos, game);
    xp_bar = xp_bar_create(pos, size, game->player->xp,
        game->player->max_xp);
    return xp_bar;
}

void game_xp_bar_update(game_t *game)
{
    sfVector2f pos = sfView_getCenter(game->cam->view);

    pos = offset_pos(pos, game);
    xp_bar_update(game->xp_bar, pos, game->player->xp);
}
