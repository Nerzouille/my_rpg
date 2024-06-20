/*
** EPITECH PROJECT, 2024
** main_game
** File description:
** def collisions
*/

#include "../../include/my_rpg.h"
#include "../../include/map.h"

void collision_def(game_t *game, map_t *map, int i, int j)
{
    if (map->collisions[i][j] != -1) {
        game->obstacle_list = add_obstacle_to_obstacle_list(
            game->obstacle_list,
        obstacle_create((sfVector2f){j * 48, i * 48}));
    }
}

int def_collide(game_t *game, map_t *map)
{
    game->didacticiel = 0;
    for (int i = 0; i < MAP_SIZE; i++)
        for (int j = 0; j < MAP_SIZE; j++)
            collision_def(game, map, i, j);
    add_door_coll(game);
    return 0;
}

int **open_csv_coll(char *path)
{
    int file = open(path, O_RDONLY);
    int len_v;
    struct stat len_s;
    char *buffer;
    int **csv;

    stat(path, &len_s);
    len_v = len_s.st_size;
    buffer = malloc(sizeof(char) * (len_v + 1));
    read(file, buffer, len_v);
    buffer[len_v] = '\0';
    csv = def_csv_tab(buffer);
    close(file);
    return csv;
}
