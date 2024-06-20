/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** bullet
*/

#ifndef BULLET_H_
    #define BULLET_H_

    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Types.h>
    #include <SFML/System/Vector2.h>

    #define MAX_BULLET_TIME 5000000
    #define BULLET_TEXTURE_WIDTH 16
    #define BULLET_TEXTURE_HEIGHT 16

typedef struct game_s game_t;

enum bullet_type {
    PLAYER_BULLET,
    MOB_BULLET
};

typedef struct bullet_s {
    sfVector2f pos;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect hitbox;
    sfIntRect texture_rect;
    sfVector2f direction;
    sfClock *clock;
    sfClock *texture_clock;
    int speed;
    int damage;
    int id;
    enum bullet_type type;
    int destroy;
}bullet_t;

bullet_t *bullet_create(sfVector2f pos, sfVector2f direction,
    int speed, int damage);
void bullet_update(bullet_t *bullet);
void bullet_display(bullet_t *bullet, sfRenderWindow *window);
void bullet_destroy(bullet_t *bullet);
void set_bullet_type(bullet_t *bullet, enum bullet_type type);

typedef struct bullet_list_s {
    bullet_t *bullet;
    struct bullet_list_s *next;
}bullet_list_t;

bullet_list_t *destroy_bullet_in_list(bullet_list_t *list, bullet_t *bullet);
bullet_list_t *add_bullet_to_bullet_list(bullet_list_t *list,
    bullet_t *bullet);
bullet_list_t *update_bullet_list(bullet_list_t *list);
void display_bullet_list(bullet_list_t *list, sfRenderWindow *window);
void destroy_bullet_list(bullet_list_t *list);

// collisions
void check_collision_bullet_mob(game_t *game);
void check_collision_bullet_player(game_t *game);
void check_collision_bullet_obstacle(game_t *game);

#endif /* !BULLET_H_ */
