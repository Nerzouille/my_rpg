/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** game_destroy
*/

#include "../include/my_rpg.h"

void game_destroy(game_t *game)
{
    save_game(game);
    player_destroy(game->player);
    map_destroy(game);
    for (int i = 0; i < game->nb_spawner; i++)
        spawner_destroy(game->spawners[i]);
    for (int i = 0; i < game->nb_d_spawner; i++)
        d_spawner_destroy(game->d_spawners[i]);
    sfTexture_destroy(game->map->tileset);
    destroy_bullet_list(game->bullet_list);
    obstacle_list_destroy(game->obstacle_list);
    dial_destroy(game);
    mob_list_destroy(game->mob_list);
    dest_songs(game);
    camera_destroy(game->cam);
    health_bar_destroy(game->health_bar);
    free(game);
}
