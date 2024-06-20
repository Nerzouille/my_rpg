/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** render_weapon.c
*/

#include "../../include/my_rpg.h"

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/System/Vector2.h>

void render_all_slot(game_t *game, inventory_t *inventory,
    sfRenderWindow *window)
{
    int sniper_nb = get_sniper_nb(game, inventory);
    int smg_nb = get_smg_nb(game, inventory);
    int nb_ar = get_ar_nb(game, inventory);
    int nb_pistol = get_pistol_nb(game, inventory);

    render_sniper_slots(game, inventory, window, sniper_nb);
    render_smg_slots(game, inventory, window, smg_nb);
    render_assault_slots(game, inventory, window, nb_ar);
    render_pistol_slots(game, inventory, window, nb_pistol);
}
