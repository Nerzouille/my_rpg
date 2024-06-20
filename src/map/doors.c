/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** dispaly
*/

#include "../../include/my_rpg.h"

void create_doors_s(game_t *game)
{
    game->map->door_t = sfTexture_createFromFile("assets/door.png", NULL);
    game->map->door_s = malloc(sizeof(sfSprite *) * 3);
    game->map->tab_doors = malloc(sizeof(int) * 3);
    for (int i = 0; i < 3; i++) {
        game->map->door_s[i] = sfSprite_create();
        sfSprite_setTexture(game->map->door_s[i], game->map->door_t, sfTrue);
        game->map->tab_doors[i] = 1;
    }
    sfSprite_setPosition(game->map->door_s[0],
        (sfVector2f){5616, 3984});
    sfSprite_setPosition(game->map->door_s[1],
        (sfVector2f){3792, 4656});
    sfSprite_setPosition(game->map->door_s[2],
        (sfVector2f){4176, 6288});
}

void update_doors_s(game_t *game)
{
    static int prec = 0;

    if (game->player->keys == 1 && prec != 1) {
        game->map->tab_doors[2] = 0;
    }
    if (game->player->keys == 2 && prec != 2) {
        game->map->tab_doors[1] = 0;
    }
    if (game->player->keys == 3 && prec != 3) {
        game->map->tab_doors[0] = 0;
    }
}

void draw_doors_s(sfRenderWindow *window, game_t *game)
{
    for (int i = 0; i < 3 && game->map->tab_doors[i] != 0; i++)
        sfRenderWindow_drawSprite(window, game->map->door_s[i], NULL);
}

void destroy_doors_s(game_t *game)
{
    for (int i = 0; i < 3; i++)
        sfSprite_destroy(game->map->door_s[i]);
    sfTexture_destroy(game->map->door_t);
}
