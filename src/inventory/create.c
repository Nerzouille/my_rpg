/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** create
*/

#include "../../include/my_rpg.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Texture.h>

static inventory_t *create_weapon_slot(inventory_t *inventory)
{
    inventory->weapon_slot = "pistol";
    inventory->weapon_texture = sfTexture_createFromFile
        ("assets/pistol.png", NULL);
    inventory->weapon_sprite = sfSprite_create();
    return inventory;
}

static inventory_t *create_slot(inventory_t *inventory)
{
    inventory->slot_one = NULL;
    inventory->slot_one_texture = sfTexture_create(10, 10);
    inventory->slot_one_sprite = sfSprite_create();
    inventory->slot_two = "assault";
    inventory->slot_two_texture =
        sfTexture_createFromFile("assets/ar.png", NULL);
    inventory->slot_two_sprite = sfSprite_create();
    inventory->slot_tree = "smg";
    inventory->slot_tree_texture =
        sfTexture_createFromFile("assets/smg.png", NULL);
    inventory->slot_tree_sprite = sfSprite_create();
    inventory->slot_four = "sniper";
    inventory->slot_four_texture =
        sfTexture_createFromFile("assets/smg.png", NULL);
    inventory->slot_four_sprite = sfSprite_create();
    return inventory;
}

inventory_t *create_inv(void)
{
    inventory_t *inventory;

    inventory = malloc(sizeof(inventory_t));
    inventory->is_open = 0;
    inventory->inventory_texture = sfTexture_createFromFile(
        "assets/inventory.png", NULL);
    inventory->inventory_sprite = sfSprite_create();
    inventory->inv_pressed_clock = sfClock_create();
    inventory->slot_pressed_clock = sfClock_create();
    inventory = create_slot(inventory);
    inventory->item_taked = NULL;
    inventory->shield_slot = NULL;
    inventory->helmet_slot = NULL;
    inventory = create_weapon_slot(inventory);
    inventory->slot_taken = 0;
    inventory->is_taked = 0;
    return inventory;
}
