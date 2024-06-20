/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** handle_event.c
*/

#include "../../include/my_rpg.h"

#include <SFML/Graphics/Sprite.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>

static void click_first_slot(game_t *game, inventory_t *inventory,
    sfVector2i mouse_pos)
{
    if (inventory->item_taked == NULL) {
        inventory->item_taked = inventory->slot_one;
        inventory->slot_one = NULL;
    } else if (inventory->slot_one == NULL) {
        inventory->slot_one = inventory->item_taked;
        inventory->item_taked = NULL;
    }
}

static void click_second_slot(game_t *game, inventory_t *inventory,
    sfVector2i mouse_pos)
{
    if (inventory->item_taked == NULL) {
        inventory->item_taked = inventory->slot_two;
        inventory->slot_two = NULL;
    } else if (inventory->slot_two == NULL) {
        inventory->slot_two = inventory->item_taked;
        inventory->item_taked = NULL;
    }
}

static void click_third_slot(game_t *game, inventory_t *inventory,
    sfVector2i mouse_pos)
{
    if (inventory->item_taked == NULL) {
        inventory->item_taked = inventory->slot_tree;
        inventory->slot_tree = NULL;
    } else if (inventory->slot_tree == NULL) {
        inventory->slot_tree = inventory->item_taked;
        inventory->item_taked = NULL;
    }
}

static void click_fourth_slot(game_t *game, inventory_t *inventory,
    sfVector2i mouse_pos)
{
    if (inventory->item_taked == NULL) {
        inventory->item_taked = inventory->slot_four;
        inventory->slot_four = NULL;
    } else if (inventory->slot_four == NULL){
        inventory->slot_four = inventory->item_taked;
        inventory->item_taked = NULL;
    }
}

void call_first_slot_1920(game_t *game, inventory_t *inventory,
    sfVector2i mouse_pos)
{
    if ((mouse_pos.x > 832 && mouse_pos.x < 915) &&
        (mouse_pos.y > 570 && mouse_pos.y < 660) &&
        sfClock_getElapsedTime(inventory->slot_pressed_clock).microseconds
        > 200000) {
            click_first_slot(game, inventory, mouse_pos);
            sfSound_play(game->sound_button);
    }
    if ((mouse_pos.x > 940 && mouse_pos.x < 1025) &&
        (mouse_pos.y > 570 && mouse_pos.y < 660) &&
        sfClock_getElapsedTime(inventory->slot_pressed_clock).microseconds
        > 200000) {
            click_second_slot(game, inventory, mouse_pos);
            sfSound_play(game->sound_button);
    }
}

static void call_first_slot_1280(game_t *game, inventory_t *inventory,
    sfVector2i mouse_pos)
{
    if ((mouse_pos.x > 510 && mouse_pos.x < 600) &&
        (mouse_pos.y > 390 && mouse_pos.y < 480) &&
        sfClock_getElapsedTime(inventory->slot_pressed_clock).microseconds
        > 200000) {
            click_first_slot(game, inventory, mouse_pos);
            sfSound_play(game->sound_button);
    }
    if ((mouse_pos.x > 620 && mouse_pos.x < 705) &&
        (mouse_pos.y > 390 && mouse_pos.y < 480) &&
        sfClock_getElapsedTime(inventory->slot_pressed_clock).microseconds
        > 200000) {
            click_second_slot(game, inventory, mouse_pos);
            sfSound_play(game->sound_button);
    }
}

static void call_last_slot_1920(game_t *game, inventory_t *inventory,
    sfVector2i mouse_pos)
{
    if ((mouse_pos.x > 1045 && mouse_pos.x < 1135) &&
        (mouse_pos.y > 570 && mouse_pos.y < 660) &&
        sfClock_getElapsedTime(inventory->slot_pressed_clock).microseconds
        > 200000) {
            click_third_slot(game, inventory, mouse_pos);
            sfSound_play(game->sound_button);
    }
    if ((mouse_pos.x > 1155 && mouse_pos.x < 1240) &&
        (mouse_pos.y > 570 && mouse_pos.y < 660) &&
        sfClock_getElapsedTime(inventory->slot_pressed_clock).microseconds
        > 200000) {
            click_fourth_slot(game, inventory, mouse_pos);
            sfSound_play(game->sound_button);
    }
    close_when_cross(game, inventory, mouse_pos);
}

static void call_last_slot_1280(game_t *game, inventory_t *inventory,
    sfVector2i mouse_pos)
{
    if ((mouse_pos.x > 730 && mouse_pos.x < 815) &&
        (mouse_pos.y > 390 && mouse_pos.y < 480) &&
        sfClock_getElapsedTime(inventory->slot_pressed_clock).microseconds
        > 200000) {
            click_third_slot(game, inventory, mouse_pos);
            sfSound_play(game->sound_button);
    }
    if ((mouse_pos.x > 835 && mouse_pos.x < 920) &&
        (mouse_pos.y > 390 && mouse_pos.y < 480) &&
        sfClock_getElapsedTime(inventory->slot_pressed_clock).microseconds
        > 200000) {
            click_fourth_slot(game, inventory, mouse_pos);
            sfSound_play(game->sound_button);
    }
    close_when_cross_1280(game, inventory, mouse_pos);
}

int check_click_inv(game_t *game, inventory_t *inventory)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);

    if (sfRenderWindow_getSize(game->window).x == 1920) {
        call_first_slot_1920(game, inventory, mouse_pos);
        call_last_slot_1920(game, inventory, mouse_pos);
        call_special_slots_1920(game, inventory, mouse_pos);
    } else {
        call_first_slot_1280(game, inventory, mouse_pos);
        call_last_slot_1280(game, inventory, mouse_pos);
        call_special_slots_1280(game, inventory, mouse_pos);
    }
    return 0;
}

void handle_event_inv(game_t *game, sfRenderWindow *window)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && game->inventory->is_open
    && sfClock_getElapsedTime(game->inventory->slot_pressed_clock).microseconds
    > 100000) {
        check_click_inv(game, game->inventory);
        sfClock_restart(game->inventory->slot_pressed_clock);
    }
    return;
}
