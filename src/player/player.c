/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** player
*/

#include "../../include/my_rpg.h"

static void player_create_sprite(player_t *player, sfVector2f pos)
{
    int h_ratio = PLAYER_TOTAL_HEIGHT / PLAYER_TEXTURE_HEIGHT;
    int w_ratio = PLAYER_TOTAL_WIDTH / PLAYER_TEXTURE_WIDTH;

    player->sprite = sfSprite_create();
    player->texture = sfTexture_createFromFile("assets/player.png", NULL);
    sfSprite_setTexture(player->sprite, player->texture, sfFalse);
    player->texture_rect = (sfIntRect){0, 0,
        PLAYER_TEXTURE_WIDTH, PLAYER_TEXTURE_HEIGHT};
    sfSprite_setTextureRect(player->sprite, player->texture_rect);
    sfSprite_setScale(player->sprite, (sfVector2f){w_ratio, h_ratio});
    player->hitbox = (sfIntRect){
        pos.x + ((float)PLAYER_TOTAL_WIDTH / 4),
        pos.y + ((float)PLAYER_TOTAL_HEIGHT / 4),
        PLAYER_TOTAL_WIDTH / 2, PLAYER_TOTAL_HEIGHT / 2};
}

player_t *player_create(sfVector2f pos)
{
    player_t *player = malloc(sizeof(player_t));

    player->pos = pos;
    player->speed = 3;
    player->alive = 1;
    player->health = 100;
    player->health_max = 100;
    player->texture_clock = sfClock_create();
    player->last_pos = pos;
    player->gun = NULL;
    player_create_sprite(player, pos);
    player->death_clock = NULL;
    player->xp = 0;
    player->max_xp = PLAYER_MAX_XP;
    player->level = 1;
    player->hit = 0;
    player->pieces = 0;
    player->keys = 0;
    return player;
}

void player_display(player_t *player, sfRenderWindow *window)
{
    float angle;

    if (player->gun != NULL)
        angle = vector_get_angle(player->gun->direction);
    if (player->gun != NULL && angle < 0)
        sfRenderWindow_drawSprite(window, player->gun->sprite, NULL);
    sfRenderWindow_drawSprite(window, player->sprite, NULL);
    if (player->gun != NULL && angle >= 0)
        sfRenderWindow_drawSprite(window, player->gun->sprite, NULL);
}

void player_destroy(player_t *player)
{
    sfSprite_destroy(player->sprite);
    sfTexture_destroy(player->texture);
    sfClock_destroy(player->texture_clock);
    if (player->death_clock != NULL)
        sfClock_destroy(player->death_clock);
    free(player);
}
