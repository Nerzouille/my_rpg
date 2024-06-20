/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** collision
*/

#include "../../include/my_rpg.h"
#include "../../include/map.h"

void rm_last_door(game_t *game)
{
    obstacle_list_t *obstacle = game->obstacle_list;

    game->obstacle_list = game->obstacle_list->next;
    free(obstacle);
}

static void doors_music(game_t *game)
{
    sfMusic_stop(game->mus_tuto);
    sfMusic_play(game->mus_game);
}

void doors_update(game_t *game)
{
    static int prev_key = 0;

    if (game->player->keys < prev_key)
        game->player->keys = prev_key;
    if (game->player->keys == 0 && game->player->xp >= XP_GAIN * 2) {
        game->player->keys++;
        game->ui->dial->conv = open_txt_file("assets/txt/first_key.txt");
        doors_music(game);
    }
    if (game->player->keys == 1 && check_collision(game->player->hitbox,
        (sfIntRect){2769, 5984, 80, 84}) == 1)
        game->player->keys++;
    if (game->player->keys == 2 && check_collision(game->player->hitbox,
        (sfIntRect){7279, 3391, 161, 133}) == 1)
        game->player->keys++;
    if (prev_key != game->player->keys && prev_key != 3) {
        rm_last_door(game);
        prev_key = game->player->keys;
    }
    main_dials(game);
}

void add_door_coll(game_t *game)
{
    game->obstacle_list = add_obstacle_to_obstacle_list(
        game->obstacle_list,
        obstacle_create((sfVector2f){5616, 4032}));
    game->obstacle_list = add_obstacle_to_obstacle_list(
        game->obstacle_list,
        obstacle_create((sfVector2f){3792, 4684}));
    game->obstacle_list = add_obstacle_to_obstacle_list(
        game->obstacle_list,
        obstacle_create((sfVector2f){4176, 6336}));
}
