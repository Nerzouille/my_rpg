/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** collision
*/

#include "../../include/obstacle.h"
#include "../../include/player.h"
#include "../../include/mobs.h"
#include "../../include/utils.h"
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>

static void handle_collision_player(player_t *player, obstacle_t *obstacle)
{
    player_set_pos(player, player->last_pos);
}

static void handle_collision_mob(mob_t *mob, obstacle_t *obstacle)
{
    mob_set_position(mob, mob->last_pos);
}

int check_collision_player_obstacle(player_t *player, obstacle_list_t *list)
{
    obstacle_list_t *tmp = list;

    while (tmp != NULL){
        if (check_collision(player->hitbox, tmp->obstacle->rect))
            handle_collision_player(player, tmp->obstacle);
        tmp = tmp->next;
    }
    return 0;
}

int check_collision_mob_obstacle(mob_t *mob, obstacle_list_t *list)
{
    obstacle_list_t *tmp = list;

    while (tmp != NULL){
        if (check_collision(mob->hitbox, tmp->obstacle->rect))
            handle_collision_mob(mob, tmp->obstacle);
        tmp = tmp->next;
    }
    return 0;
}
