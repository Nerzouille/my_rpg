/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** special_slots.c
*/

#include "../../include/my_rpg.h"
#include <SFML/System/Clock.h>
#include <stdbool.h>

// NOTE: Chanage the name with the actual name of the shield
static bool check_shield(game_t *game, inventory_t *inventory)
{
    char *list_shield[] = {
        "iron_shield",
        "ion_shield",
        NULL
    };

    for (int i = 0; list_shield[i] != NULL; i++)
        if (my_strcmp(inventory->item_taked, list_shield[i]) == 0)
            return true;
    return false;
}

static bool check_helmet(game_t *game, inventory_t *inventory)
{
    char *list_helmet[] = {
        "iron_helmet",
        "night_vision",
        NULL
    };

    for (int i = 0; list_helmet[i] != NULL; i++)
        if (my_strcmp(inventory->item_taked, list_helmet[i]) == 0)
            return true;
    return false;
}

static bool check_weapon(game_t *game, inventory_t *inventory)
{
    char *list_weapon[] = {
        "pistol",
        "assault",
        "smg",
        "sniper",
        NULL
    };

    for (int i = 0; list_weapon[i] != NULL; i++)
        if (my_strcmp(inventory->item_taked, list_weapon[i]) == 0)
            return true;
    return false;
}

static void click_shield_slot(game_t *game, inventory_t *inventory)
{
    if (inventory->item_taked == NULL) {
        inventory->item_taked = inventory->shield_slot;
        inventory->shield_slot = NULL;
    } else if (inventory->shield_slot == NULL &&
        check_shield(game, inventory)) {
        inventory->shield_slot = inventory->item_taked;
        inventory->item_taked = NULL;
    }
}

static void click_helmet_slot(game_t *game, inventory_t *inventory)
{
    if (inventory->item_taked == NULL) {
        inventory->item_taked = inventory->helmet_slot;
        inventory->helmet_slot = NULL;
    } else if (inventory->helmet_slot == NULL &&
        check_helmet(game, inventory)) {
        inventory->helmet_slot = inventory->item_taked;
        inventory->item_taked = NULL;
    }
}

static void click_weapon_slot(game_t *game, inventory_t *inventory)
{
    if (inventory->item_taked == NULL) {
        inventory->item_taked = inventory->weapon_slot;
        inventory->weapon_slot = NULL;
    } else if (inventory->weapon_slot == NULL &&
        check_weapon(game, inventory)) {
        inventory->weapon_slot = inventory->item_taked;
        inventory->item_taked = NULL;
    }
}

void cord_special_slot_1920(game_t *game, inventory_t *inventory,
    sfVector2i mouse_pos)
{
    if ((mouse_pos.x > 825 && mouse_pos.x < 910) &&
        (mouse_pos.y > 333 && mouse_pos.y < 420) &&
        (sfClock_getElapsedTime(inventory->slot_pressed_clock).microseconds
        > 200000))
        click_shield_slot(game, inventory);
    if ((mouse_pos.x > 990 && mouse_pos.x < 1075) &&
        (mouse_pos.y > 333 && mouse_pos.y < 420) &&
        (sfClock_getElapsedTime(inventory->slot_pressed_clock).microseconds
        > 200000))
        click_helmet_slot(game, inventory);
    if ((mouse_pos.x > 1155 && mouse_pos.x < 1240) &&
        (mouse_pos.y > 333 && mouse_pos.y < 420) &&
        (sfClock_getElapsedTime(inventory->slot_pressed_clock).microseconds
        > 200000))
        click_weapon_slot(game, inventory);
}

void cord_special_slot_1280(game_t *game, inventory_t *inventory,
    sfVector2i mouse_pos)
{
    if ((mouse_pos.x > 505 && mouse_pos.x < 595) &&
        (mouse_pos.y > 155 && mouse_pos.y < 240) &&
        (sfClock_getElapsedTime(inventory->slot_pressed_clock).microseconds
        > 200000))
        click_shield_slot(game, inventory);
    if ((mouse_pos.x > 670 && mouse_pos.x < 760) &&
        (mouse_pos.y > 155 && mouse_pos.y < 240) &&
        (sfClock_getElapsedTime(inventory->slot_pressed_clock).microseconds
        > 200000))
        click_helmet_slot(game, inventory);
    if ((mouse_pos.x > 825 && mouse_pos.x < 910) &&
        (mouse_pos.y > 155 && mouse_pos.y < 240) &&
        (sfClock_getElapsedTime(inventory->slot_pressed_clock).microseconds
        > 200000))
        click_weapon_slot(game, inventory);
}

void call_special_slots_1280(game_t *game, inventory_t *inventory,
    sfVector2i mouse_pos)
{
    cord_special_slot_1280(game, inventory, mouse_pos);
}

void call_special_slots_1920(game_t *game, inventory_t *inventory,
    sfVector2i mouse_pos)
{
    cord_special_slot_1920(game, inventory, mouse_pos);
}
