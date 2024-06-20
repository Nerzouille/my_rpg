/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** player
*/
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Types.h>
#include <SFML/System/Vector2.h>

#ifndef PLAYER_H_
    #define PLAYER_H_

    #define PLAYER_TEXTURE_WIDTH 32
    #define PLAYER_TEXTURE_HEIGHT 32
    #define PLAYER_TOTAL_WIDTH 64
    #define PLAYER_TOTAL_HEIGHT 64
    #define PLAYER_MAX_XP 100
    #define PLAYER_HIT_FRAME 3

typedef struct game_s game_t;
typedef struct gun_s gun_t;

typedef struct player_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect texture_rect;
    sfIntRect hitbox;
    sfClock *texture_clock;
    sfVector2f pos;
    sfVector2f last_pos;
    sfVector2f direction;
    gun_t *gun;
    int speed;
    int alive;
    int health;
    int health_max;
    sfClock *death_clock;
    int xp;
    int max_xp;
    int level;
    int hit;
    int keys;
    int pieces;
}player_t;

void open_save(game_t *game);
void save_game(game_t *game);

player_t *player_create(sfVector2f pos);
void player_display(player_t *player, sfRenderWindow *window);
void player_destroy(player_t *player);
void player_update(game_t *game, player_t *player,
    sfRenderWindow *window, sfView *view);
void player_handle_input(player_t *player, game_t *game,
    sfRenderWindow *window);
void player_set_pos(player_t *player, sfVector2f pos);

#endif /* !PLAYER_H_ */
