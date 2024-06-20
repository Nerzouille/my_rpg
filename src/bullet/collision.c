/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** collision
*/

#include "../../include/my_rpg.h"

static void collision_bullet_mob(game_t *game, bullet_t *bullet, mob_t *mob)
{
    if (check_collision(bullet->hitbox, mob->hitbox) == 1) {
        mob->health -= bullet->damage;
        bullet->destroy = 1;
    }
}

void check_collision_bullet_mob(game_t *game)
{
    bullet_list_t *current = game->bullet_list;
    bullet_list_t *next;
    mob_list_t *current_mob;
    mob_list_t *next_mob;

    while (current != NULL) {
        next = current->next;
        if (current->bullet->type != PLAYER_BULLET){
            current = next;
            continue;
        }
        current_mob = game->mob_list;
        while (current_mob != NULL) {
            next_mob = current_mob->next;
            collision_bullet_mob(game, current->bullet, current_mob->mob);
            current_mob = next_mob;
        }
        current = next;
    }
}

static void collision_bullet_obstcle(game_t *game, bullet_t *bullet,
    obstacle_t *obstacle)
{
    if (check_collision(bullet->hitbox, obstacle->rect) == 1) {
        bullet->destroy = 1;
    }
}

void check_collision_bullet_obstacle(game_t *game)
{
    bullet_list_t *current = game->bullet_list;
    bullet_list_t *next;
    obstacle_list_t *current_obstacle;
    obstacle_list_t *next_obstacle;

    while (current != NULL) {
        next = current->next;
        current_obstacle = game->obstacle_list;
        while (current_obstacle != NULL) {
            next_obstacle = current_obstacle->next;
            collision_bullet_obstcle(game, current->bullet,
                current_obstacle->obstacle);
            current_obstacle = next_obstacle;
        }
        current = next;
    }
}

void check_collision_bullet_player(game_t *game)
{
    bullet_list_t *current = game->bullet_list;
    bullet_list_t *next;

    while (current != NULL) {
        next = current->next;
        if (current->bullet->type != MOB_BULLET){
            current = next;
            continue;
        }
        if (check_collision(current->bullet->hitbox,
            game->player->hitbox) == 1){
            game->player->health -= current->bullet->damage;
            game->player->hit = PLAYER_HIT_FRAME;
            current->bullet->destroy = 1;
        }
        current = next;
    }
}
