/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** game
*/

#include "../../include/my_rpg.h"

void d_def_spawn(game_t *game, char **tab)
{
    static int n_spawn = 0;
    sfVector2f pos = (sfVector2f){my_getnbr(tab[0]), my_getnbr(tab[1])};

    game->d_spawners[n_spawn] = d_spawner_create(pos, D_SPAWN_RATE,
        (sfVector2f){my_getnbr(tab[2]), my_getnbr(tab[3])}, tab[4]);
    n_spawn++;
}

void d_spawn_tab(game_t *game, char **tab, int i)
{
    char **spawn;

    spawn = my_str_in_array(tab[i]);
    d_def_spawn(game, spawn);
}

void d_open_spwans(game_t *game, char *path)
{
    int file = open(path, O_RDONLY);
    int len_v;
    struct stat len_s;
    char *buffer;
    int **tab_spawn;
    char **tab;

    stat(path, &len_s);
    len_v = len_s.st_size;
    buffer = malloc(sizeof(char) * (len_v + 1));
    read(file, buffer, len_v);
    buffer[len_v] = '\0';
    tab = my_str_in_array_txt(buffer);
    for (int i = 0; tab[i] != NULL; i++)
        d_spawn_tab(game, tab, i);
    close(file);
    return;
}

void d_spawner_destroy(dial_spawner_t *spawner)
{
    free(spawner->path);
    free(spawner);
}

void disp_hitbox(game_t *game, sfRenderWindow *window)
{
    for (int i = 0; i < game->nb_spawner; i++)
        spawner_displaye(window, game->spawners[i]);
    for (int i = 0; i < game->nb_d_spawner; i++)
        d_spawner_display(window, game->d_spawners[i]);
}
