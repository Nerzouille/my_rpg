/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** dispaly
*/

#include "../../include/my_rpg.h"

void tiles_disp(sfRenderWindow *window, tile_list_t *map)
{
    tile_list_t *current = map;
    tile_list_t *prev = current;

    while (current != NULL) {
        sfRenderWindow_drawSprite(window, current->tile, NULL);
        current = current->next;
    }
}

void obj_disp(sfRenderWindow *window, game_t *game, tile_list_t *current)
{
    tile_list_t *prev = current;

    while (current != NULL) {
        if (sfSprite_getPosition(current->tile).y > game->player->pos.y - 2)
            sfRenderWindow_drawSprite(window, current->tile, NULL);
        current = current->next;
    }
}

void parralax(sfRenderWindow *window, game_t *game)
{
    obj_disp(window, game, game->map->lab);
    obj_disp(window, game, game->map->lab2);
    obj_disp(window, game, game->map->obj_c);
}

void map_display(game_t *game, sfRenderWindow *window)
{
    int x = game->player->pos.x - sfView_getSize(game->cam->view).x / 2;
    int y = game->player->pos.y - sfView_getSize(game->cam->view).y / 2;

    sfSprite_setPosition(game->map->bg_spr, (sfVector2f){x, y});
    sfRenderWindow_drawSprite(window, game->map->bg_spr, NULL);
    tiles_disp(window, game->map->lim);
    tiles_disp(window, game->map->calcu);
    tiles_disp(window, game->map->floor);
    draw_doors_s(window, game);
    tiles_disp(window, game->map->lab);
    tiles_disp(window, game->map->lab2);
    tiles_disp(window, game->map->obj_c);
}

static void tiles_destroying(tile_list_t *map)
{
    tile_list_t *current = map;

    while (current != NULL) {
        sfSprite_destroy(current->tile);
        current = current->next;
    }
}

void map_destroy(game_t *game)
{
    tiles_destroying(game->map->lim);
    tiles_destroying(game->map->calcu);
    tiles_destroying(game->map->floor);
    tiles_destroying(game->map->lab2);
    tiles_destroying(game->map->lab);
    tiles_destroying(game->map->obj_c);
    destroy_doors_s(game);
}
