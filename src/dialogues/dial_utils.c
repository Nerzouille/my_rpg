/*
** EPITECH PROJECT, 2024
** main_game
** File description:
** dialogues destroy
*/

#include "../../include/my_rpg.h"

void d_spawner_display(sfRenderWindow *window, dial_spawner_t *spawner)
{
    display_hitbox(spawner->hitbox, window);
}

void create_d_spawner(game_t *game)
{
    game->d_spawners = malloc(sizeof(dial_spawner_t) * 14);
    game->nb_d_spawner = 13;
}

void dial_destroy(game_t *game)
{
    sfRectangleShape_destroy(game->ui->dial->dialBox);
    sfText_destroy(game->ui->dial->nameText);
    sfText_destroy(game->ui->dial->dialText);
    sfFont_destroy(game->ui->dial->font);
}

dial_spawner_t *d_spawner_create(sfVector2f pos,
    int spawn_rate, sfVector2f size, char *path)
{
    dial_spawner_t *spawner = malloc(sizeof(dial_spawner_t));

    spawner->pos = pos;
    spawner->spawn_rate = spawn_rate;
    spawner->view = 0;
    spawner->path = path;
    spawner->hitbox = (sfIntRect){pos.x, pos.y, size.x, size.y};
    return spawner;
}

void d_spawner_update(dial_spawner_t *spawner, game_t *game)
{
    if (spawner->view == 0 && check_collision(game->player->hitbox,
            spawner->hitbox) && game->freeze_game == 0) {
        spawner->view = 1;
        game->ui->dial->conv = open_txt_file(spawner->path);
    }
}
