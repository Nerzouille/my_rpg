/*
** EPITECH PROJECT, 2024
** main_game
** File description:
** dialogues destroy
*/

#include "../../include/my_rpg.h"

void pieces_update_s(game_t *game)
{
    static int tres = 0;

    if (check_collision(game->player->hitbox,
        (sfIntRect){6115, 2160, 188, 98}) == 1 && tres == 0){
        game->player->pieces++;
        tres = 1;
    }
}

void pieces_update(game_t *game)
{
    static int prev_pieces = 0;
    static int uno = 0;
    static int dos = 0;

    if (game->player->pieces < prev_pieces)
        game->player->pieces = prev_pieces;
    if (check_collision(game->player->hitbox,
        (sfIntRect){2640, 4176, 71, 74}) == 1 && uno == 0) {
        game->player->pieces++;
        uno = 1;
    }
    if (check_collision(game->player->hitbox,
        (sfIntRect){5876, 6528, 124, 118}) == 1 && dos == 0){
        game->player->pieces++;
        dos = 1;
    }
    pieces_update_s(game);
}

void didact(game_t *game)
{
    static int didac = 0;

    if (didac == 0 && check_collision(game->player->hitbox,
        (sfIntRect){4176, 6384, 48, 10}) == 1) {
        game->didacticiel = 1;
        didac = 1;
    }
}

void main_dials(game_t *game)
{
    static int ficha = 0;

    pieces_update(game);
    if (game->didacticiel == 0)
        didact(game);
    if (game->player->pieces == 3 && ficha == 0 && game->freeze_game == 0) {
        game->ui->dial->conv = open_txt_file("assets/txt/all_pieces.txt");
        ficha = game->player->pieces;
    }
    if (game->player->pieces == 3 && check_collision(game->player->hitbox,
        (sfIntRect){4848, 5328, 217, 96}) == 1 && ficha == 3) {
        ficha++;
        game->ui->dial->conv = open_txt_file("assets/txt/finish.txt");
        sfMusic_stop(game->mus_game);
        sfMusic_play(game->mus_end);
    }
}
