/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** update
*/

#include "../../include/my_rpg.h"
#include <stdio.h>

void player_set_pos(player_t *player, sfVector2f pos)
{
    player->last_pos = player->pos;
    player->pos = pos;
    sfSprite_setPosition(player->sprite, player->pos);
    player->hitbox.top = player->pos.y + ((float)PLAYER_TOTAL_WIDTH / 4);
    player->hitbox.left = player->pos.x + ((float)PLAYER_TOTAL_HEIGHT / 4);
}

static int player_update_texture_rect_direction_x(player_t *player)
{
    if (player->direction.x > 0){
        if (player->direction.y > 0)
            player->texture_rect.top = PLAYER_TEXTURE_HEIGHT * 1;
        if (player->direction.y == 0)
            player->texture_rect.top = PLAYER_TEXTURE_HEIGHT * 2;
        if (player->direction.y < 0)
            player->texture_rect.top = PLAYER_TEXTURE_HEIGHT * 3;
        return 1;
    }
    if (player->direction.x < 0){
        if (player->direction.y < 0)
            player->texture_rect.top = PLAYER_TEXTURE_HEIGHT * 5;
        if (player->direction.y == 0)
            player->texture_rect.top = PLAYER_TEXTURE_HEIGHT * 6;
        if (player->direction.y > 0)
            player->texture_rect.top = PLAYER_TEXTURE_HEIGHT * 7;
        return 1;
    }
    return 0;
}

static void player_update_texture_rect_direction(player_t *player)
{
    if (player_update_texture_rect_direction_x(player))
        return;
    if (player->direction.y > 0)
        player->texture_rect.top = PLAYER_TEXTURE_HEIGHT * 0;
    if (player->direction.y < 0)
        player->texture_rect.top = PLAYER_TEXTURE_HEIGHT * 4;
    if (player->direction.y == 0 && player->direction.x == 0)
        player->texture_rect.top = 0;
}

static void player_update_texture_rect(player_t *player, game_t *game)
{
    if (sfClock_getElapsedTime(player->texture_clock).microseconds > 100000){
        player_update_texture_rect_direction(player);
        if (player->texture_rect.left >= PLAYER_TEXTURE_WIDTH * 4)
            player->texture_rect.left = 0;
        else
            player->texture_rect.left += PLAYER_TEXTURE_WIDTH;
        if ((player->direction.x == 0 && player->direction.y == 0) ||
            game->freeze_game)
            player->texture_rect.left = 0;
        if (player->hit > 0) {
            player->texture_rect.left = PLAYER_TEXTURE_WIDTH * 5;
            player->hit = player->hit - 1;
        }
        sfClock_restart(player->texture_clock);
    }
    if (player->alive == 0)
        player->texture_rect.left = PLAYER_TEXTURE_WIDTH * 7;
    sfSprite_setTextureRect(player->sprite, player->texture_rect);
}

static void player_update_death(player_t *player, game_t *game)
{
    if (player->health <= 0){
        player->alive = 0;
        player->death_clock = sfClock_create();
        player_update_texture_rect(player, game);
    }
}

static void player_update_xp(player_t *player)
{
    if (player->xp >= player->max_xp){
        player->level++;
        player->xp = 0;
        player->health_max += 50;
        player->health = player->health_max;
    }
}

void player_update(game_t *game, player_t *player,
    sfRenderWindow *window, sfView *view)
{
    if (player->alive == 0)
        return;
    player_update_texture_rect(player, game);
    if (game->freeze_game == 0)
        player_set_pos(player, (sfVector2f){
            player->pos.x + player->speed * player->direction.x,
            player->pos.y + player->speed * player->direction.y});
    if (player->gun != NULL)
        gun_update(player->gun, player->pos, window, view);
    player_update_xp(player);
    player_update_death(player, game);
}
