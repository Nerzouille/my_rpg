/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** render_smg.c
*/

#include "../../include/game.h"

static void render_smg(game_t *game, inventory_t *inventory,
    sfRenderWindow *window, sfVector2f pos)
{
    sfTexture_destroy(inventory->slot_two_texture);
    inventory->slot_two_texture =
        sfTexture_createFromFile("assets/smg.png", NULL);
    sfSprite_setTexture(inventory->slot_two_sprite,
        inventory->slot_two_texture, sfTrue);
    sfSprite_setScale(inventory->slot_two_sprite,
        (sfVector2f) {0.75, 0.75});
    sfSprite_setPosition(inventory->slot_two_sprite,
        pos);
    sfRenderWindow_drawSprite(window, inventory->slot_two_sprite, NULL);
}

static void render_taken_smg(game_t *game, inventory_t *inventory,
    sfRenderWindow *window, int slots)
{
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(game->window);
    sfVector2i mouse_pos_window =
        sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse_pos_world =
        sfRenderWindow_mapPixelToCoords(game->window, mouse_pos_window,
        game->cam->view);

    if (slots == 6)
        render_smg(game, inventory, window,
            (sfVector2f){mouse_pos_world.x - 25, mouse_pos_world.y - 20});
}

void render_smg_slots(game_t *game, inventory_t *inventory,
    sfRenderWindow *window, int slots)
{
    if (slots == 1)
        render_smg(game, inventory, window,
            (sfVector2f){POS.x - 71, POS.y + 10});
    if (slots == 2)
        render_smg(game, inventory, window,
            (sfVector2f){POS.x - 16, POS.y + 10});
    if (slots == 3)
        render_smg(game, inventory, window,
            (sfVector2f){POS.x + 37, POS.y + 10});
    if (slots == 4)
        render_smg(game, inventory, window,
            (sfVector2f){POS.x + 90, POS.y + 10});
    if (slots == 5)
        render_smg(game, inventory, window,
            (sfVector2f) {POS.x + 85, POS.y - 110});
    render_taken_smg(game, inventory, window, slots);
}
