/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** input
*/

#include "../../include/my_rpg.h"
#include "../../include/player.h"
#include "../../include/utils.h"

#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Keyboard.h>

static void player_handle_movement(player_t *player, game_t *game)
{
    player->direction.x = 0;
    player->direction.y = 0;
    if (game->inventory->is_open)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyZ) || sfKeyboard_isKeyPressed(sfKeyW))
        player->direction.y += -1;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        player->direction.y += 1;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        player->direction.x += 1;
    if (sfKeyboard_isKeyPressed(sfKeyQ) || sfKeyboard_isKeyPressed(sfKeyA))
        player->direction.x += -1;
    player->direction = vector_normalize(player->direction);
}

static void player_handle_reload(player_t *player, game_t *game)
{
    if (game->inventory->is_open)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyR)){
        player->gun->reloading = 1;
        sfClock_restart(player->gun->clock);
    }
}

void handle_inventory(inventory_t *inventory)
{
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        if (inventory->is_open &&
        (sfClock_getElapsedTime(inventory->inv_pressed_clock).microseconds
        > 100000)) {
            sfClock_restart(inventory->inv_pressed_clock);
            inventory->is_open = 0;
        }
        if ((!inventory->is_open) &&
        (sfClock_getElapsedTime(inventory->inv_pressed_clock).microseconds
        > 100000)) {
            sfClock_restart(inventory->inv_pressed_clock);
            inventory->is_open = 1;
        }
    }
}

static void handle_inventory_input(game_t *game)
{
    game->inventory->is_open = !game->inventory->is_open;
    sfClock_restart(game->inventory->inv_pressed_clock);
}

void player_handle_input(player_t *player, game_t *game,
    sfRenderWindow *window)
{
    if (game->freeze_game == 0)
        player_handle_movement(player, game);
    player_handle_reload(player, game);
    if (sfKeyboard_isKeyPressed(sfKeyE) &&
        sfClock_getElapsedTime(game->inventory->inv_pressed_clock).microseconds
        > 200000) {
        handle_inventory_input(game);
    }
    if (game->inventory->is_open == 1) {
        handle_event_inv(game, game->window);
    }
    if ((sfKeyboard_isKeyPressed(sfKeySpace) ||
    sfMouse_isButtonPressed(sfMouseLeft)) && game->freeze_game == 0)
        if (!(game->inventory->is_open == 1))
            player_handle_shoot(player, game);
}
