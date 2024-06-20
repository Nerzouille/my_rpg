/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** game
*/

#include "../../include/my_rpg.h"

void def_spawn(game_t *game, char **tab)
{
    int i = 4;
    int j = 0;
    int nb_mob;
    static int n_spawn = 1;
    sfVector2f pos = (sfVector2f){my_getnbr(tab[0]), my_getnbr(tab[1])};
    sfVector2f *positions;

    game->spawners[n_spawn] = spawner_create(pos, SPAWN_RATE,
        (sfVector2f){my_getnbr(tab[2]), my_getnbr(tab[3])});
    for (i; tab[i] != NULL; i++);
    nb_mob = (i - 4) / 2;
    positions = malloc(sizeof(sfVector2f) * nb_mob);
    for (i = 4; tab[i] != NULL; i += 2) {
        positions[j] = (sfVector2f){my_getnbr(tab[i]), my_getnbr(tab[i + 1])};
        j++;
    }
    spawner_set_mob_positions(game->spawners[n_spawn], positions, nb_mob);
    n_spawn++;
}

void spawn_tab(game_t *game, char **tab, int i)
{
    char **spawn;

    spawn = my_str_in_array(tab[i]);
    def_spawn(game, spawn);
}

void open_spwans(game_t *game, char *path)
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
        spawn_tab(game, tab, i);
    close(file);
    return;
}
