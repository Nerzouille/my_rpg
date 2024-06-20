/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** inventory.h
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Graphics/Texture.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/Graphics/View.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Window/Keyboard.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/System/Clock.h>
    #define POS game->player->pos

typedef struct game_s game_t;

typedef struct inventory_s {
    int is_open;
    sfSprite *inventory_sprite;
    sfTexture *inventory_texture;
    sfClock *inv_pressed_clock;
    sfClock *slot_pressed_clock;

    char *slot_one;
    sfSprite *slot_one_sprite;
    sfTexture *slot_one_texture;

    char *slot_two;
    sfSprite *slot_two_sprite;
    sfTexture *slot_two_texture;

    char *slot_tree;
    sfSprite *slot_tree_sprite;
    sfTexture *slot_tree_texture;

    char *slot_four;
    sfSprite *slot_four_sprite;
    sfTexture *slot_four_texture;

    char *shield_slot;
    char *helmet_slot;

    char *weapon_slot;
    sfSprite *weapon_sprite;
    sfTexture *weapon_texture;

    int is_taked;
    int slot_taken;
    char *item_taked;
} inventory_t;

void render_inventory(game_t *game, inventory_t *inventory,
    sfRenderWindow *window);
void handle_event_inv(game_t *game, sfRenderWindow *window);
void call_special_slots_1920(game_t *game, inventory_t *inventory,
    sfVector2i mouse_pos);
void call_special_slots_1280(game_t *game, inventory_t *inventory,
    sfVector2i mouse_pos);
void render_all_slot(game_t *game, inventory_t *inventory,
    sfRenderWindow *window);
// NOTE: Get pos weapon
int get_pistol_nb(game_t *game, inventory_t *inventory);
int get_ar_nb(game_t *game, inventory_t *inventory);
int get_smg_nb(game_t *game, inventory_t *inventory);
int get_sniper_nb(game_t *game, inventory_t *inventory);

// NOTE: Slot weapon
inventory_t *create_inv(void);
void render_sniper_slots(game_t *game, inventory_t *inventory,
    sfRenderWindow *window, int slots);
void render_smg_slots(game_t *game, inventory_t *inventory,
    sfRenderWindow *window, int slots);
void render_assault_slots(game_t *game, inventory_t *inventory,
    sfRenderWindow *window, int slots);
void render_pistol_slots(game_t *game, inventory_t *inventory,
    sfRenderWindow *window, int slots);
void close_when_cross_1280(game_t *game, inventory_t *inventory,
    sfVector2i mouse_pos);
void close_when_cross(game_t *game, inventory_t *inventory,
    sfVector2i mouse_pos);

#endif /* !INVENTORY_H_ */
