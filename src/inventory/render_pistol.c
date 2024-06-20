/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** render_pistol.c
*/

#include "../../include/game.h"

static void render_pistol(game_t *game, inventory_t *inventory,
    sfRenderWindow *window, sfVector2f pos)
{
    sfTexture_destroy(inventory->slot_four_texture);
    inventory->slot_four_texture =
        sfTexture_createFromFile("assets/pistol.png", NULL);
    sfSprite_setTexture(inventory->slot_four_sprite,
        inventory->slot_four_texture, sfTrue);
    sfSprite_setScale(inventory->slot_four_sprite,
        (sfVector2f) {0.75, 0.75});
    sfSprite_setPosition(inventory->slot_four_sprite,
        pos);
    sfRenderWindow_drawSprite(window, inventory->slot_four_sprite, NULL);
}

static void render_taken_pistol(game_t *game, inventory_t *inventory,
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
        render_pistol(game, inventory, window,
            (sfVector2f){mouse_pos_world.x - 25, mouse_pos_world.y - 20});
}

void render_pistol_slots(game_t *game, inventory_t *inventory,
    sfRenderWindow *window, int slots)
{
    if (slots == 1)
        render_pistol(game, inventory, window,
            (sfVector2f){POS.x - 73, POS.y + 10});
    if (slots == 2)
        render_pistol(game, inventory, window,
            (sfVector2f){POS.x - 18, POS.y + 10});
    if (slots == 3)
        render_pistol(game, inventory, window,
            (sfVector2f){POS.x + 35, POS.y + 10});
    if (slots == 4)
        render_pistol(game, inventory, window,
            (sfVector2f){POS.x + 88, POS.y + 10});
    if (slots == 5)
        render_pistol(game, inventory, window,
            (sfVector2f){POS.x + 83, POS.y - 110});
    render_taken_pistol(game, inventory, window, slots);
}
