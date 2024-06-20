/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** collision
*/

#include "../include/my_rpg.h"

void def_songs(game_t *game)
{
    game->mus_tuto = sfMusic_createFromFile("assets/songs/shrimp.ogg");
    sfMusic_setLoop(game->mus_tuto, sfTrue);
    sfMusic_setVolume(game->mus_tuto, 50);
    game->mus_game = sfMusic_createFromFile("assets/songs/inter.ogg");
    sfMusic_setLoop(game->mus_game, sfTrue);
    sfMusic_setVolume(game->mus_game, 30);
    game->mus_end = sfMusic_createFromFile("assets/songs/jfip.ogg");
    sfMusic_setLoop(game->mus_end, sfTrue);
    sfMusic_setVolume(game->mus_end, 50);
    sfMusic_play(game->mus_tuto);
}

void dest_songs(game_t *game)
{
    sfMusic_destroy(game->mus_tuto);
    sfMusic_destroy(game->mus_game);
    sfMusic_destroy(game->mus_end);
}
