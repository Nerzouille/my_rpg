/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** get_weapon.c
*/

#include "../../include/game.h"

int get_sniper_nb(game_t *game, inventory_t *inventory)
{
    if (inventory->slot_one != NULL &&
        my_strcmp(inventory->slot_one, "sniper") == 0)
        return 1;
    if (inventory->slot_two != NULL &&
        my_strcmp(inventory->slot_two, "sniper") == 0)
        return 2;
    if (inventory->slot_tree != NULL &&
        my_strcmp(inventory->slot_tree, "sniper") == 0)
        return 3;
    if (inventory->slot_four != NULL &&
        my_strcmp(inventory->slot_four, "sniper") == 0)
        return 4;
    if (inventory->weapon_slot != NULL &&
        my_strcmp(inventory->weapon_slot, "sniper") == 0)
        return 5;
    if (inventory->item_taked != NULL &&
        my_strcmp(inventory->item_taked, "sniper") == 0)
        return 6;
    return 0;
}

int get_smg_nb(game_t *game, inventory_t *inventory)
{
    if (inventory->slot_one != NULL &&
        my_strcmp(inventory->slot_one, "smg") == 0)
        return 1;
    if (inventory->slot_two != NULL &&
        my_strcmp(inventory->slot_two, "smg") == 0)
        return 2;
    if (inventory->slot_tree != NULL &&
        my_strcmp(inventory->slot_tree, "smg") == 0)
        return 3;
    if (inventory->slot_four != NULL &&
        my_strcmp(inventory->slot_four, "smg") == 0)
        return 4;
    if (inventory->weapon_slot != NULL &&
        my_strcmp(inventory->weapon_slot, "smg") == 0)
        return 5;
    if (inventory->item_taked != NULL &&
        my_strcmp(inventory->item_taked, "smg") == 0)
        return 6;
    return 0;
}

int get_ar_nb(game_t *game, inventory_t *inventory)
{
    if (inventory->slot_one != NULL &&
        my_strcmp(inventory->slot_one, "assault") == 0)
        return 1;
    if (inventory->slot_two != NULL &&
        my_strcmp(inventory->slot_two, "assault") == 0)
        return 2;
    if (inventory->slot_tree != NULL &&
        my_strcmp(inventory->slot_tree, "assault") == 0)
        return 3;
    if (inventory->slot_four != NULL &&
        my_strcmp(inventory->slot_four, "assault") == 0)
        return 4;
    if (inventory->weapon_slot != NULL &&
        my_strcmp(inventory->weapon_slot, "assault") == 0)
        return 5;
    if (inventory->item_taked != NULL &&
        my_strcmp(inventory->item_taked, "assault") == 0)
        return 6;
    return 0;
}

int get_pistol_nb(game_t *game, inventory_t *inventory)
{
    if (inventory->slot_one != NULL &&
        my_strcmp(inventory->slot_one, "pistol") == 0)
        return 1;
    if (inventory->slot_two != NULL &&
        my_strcmp(inventory->slot_two, "pistol") == 0)
        return 2;
    if (inventory->slot_tree != NULL &&
        my_strcmp(inventory->slot_tree, "pistol") == 0)
        return 3;
    if (inventory->slot_four != NULL &&
        my_strcmp(inventory->slot_four, "pistol") == 0)
        return 4;
    if (inventory->weapon_slot != NULL &&
        my_strcmp(inventory->weapon_slot, "pistol") == 0)
        return 5;
    if (inventory->item_taked != NULL &&
        my_strcmp(inventory->item_taked, "pistol") == 0)
        return 6;
    return 0;
}
