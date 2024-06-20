/*
** EPITECH PROJECT, 2024
** main_game
** File description:
** mapping
*/

#include "../../include/my_rpg.h"
#include "../../include/my.h"
#include "../../include/map.h"
#include <string.h>
#include <SFML/Graphics/View.h>

int **def_csv_tab(char *buffer)
{
    char **csv_tab = my_str_in_array(buffer);
    int **int_csv;
    int count = 0;
    int len;

    int_csv = malloc(sizeof(int *) * MAP_SIZE);
    for (int i = 0; i < MAP_SIZE; i++)
        int_csv[i] = malloc(sizeof(int) * MAP_SIZE);
    for (int i = 0; i < MAP_SIZE; i ++)
        for (int j = 0; j < MAP_SIZE; j++) {
            int_csv[i][j] = my_getnbr(csv_tab[count]);
            count++;
        }
    return int_csv;
}

int **open_csv(char *path)
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

tile_list_t *add_tile(sfTexture *tileTextures,
    tile_list_t **list, int **csv, int i)
{
    tile_list_t *new_node = NULL;

    for (int j = 0; j < MAP_SIZE; j++) {
        if (csv[i][j] == -1)
            continue;
        new_node = malloc(sizeof(obstacle_list_t));
        new_node->tile = sfSprite_create();
        sfSprite_setTexture(new_node->tile, tileTextures, sfTrue);
        sfSprite_setTextureRect(new_node->tile,
        (sfIntRect){(csv[i][j] % 145) * 48,
        (csv[i][j] / 145) * 48, 48, 48});
        sfSprite_setPosition(new_node->tile,
        (sfVector2f){j * 48, i * 48});
        new_node->next = (*list);
        (*list) = new_node;
    }
    return new_node;
}

tile_list_t *create_calc(sfTexture *tileTextures, int **csv, tile_list_t *calc)
{
    int tile_id;
    sfSprite *tile;
    tile_list_t *new;

    if (!csv) {
        printf("Not enought memory for loading the map.\n");
        return NULL;
    }
    for (int i = 0; i < MAP_SIZE; i++)
        add_tile(tileTextures, &calc, csv, i);
    return calc;
}

tile_list_t *def_csv_l(map_t *map, tile_list_t *calc, char *path)
{
    int **csv;

    calc = NULL;
    csv = malloc(sizeof(int *) * MAP_SIZE);
    for (int i = 0; i < MAP_SIZE; i++)
        csv[i] = malloc(sizeof(int) * MAP_SIZE);
    csv = open_csv(path);
    calc = create_calc(map->tileset, csv, calc);
    if (!calc) {
        printf("Not enought memory for loading the map.\n");
        return NULL;
    }
    for (int i = 0; i < MAP_SIZE; i++)
        free(csv[i]);
    free(csv);
    return calc;
}
