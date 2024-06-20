/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** gun
*/

#ifndef GUN_H_
    #define GUN_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Types.h>
    #include <SFML/System/Vector2.h>

typedef struct game_s game_t;

typedef struct gun_blueprint_s {
    char name[256];
    int damage;
    int max_ammo;
    int fire_rate;
    int reload_time;
    int bullet_speed;
    char texture_path[256];
} gun_blueprint_t;

gun_blueprint_t *get_gun_blueprint(char *name);

typedef struct gun_s {
    char name[256];
    sfVector2f pos;
    sfVector2f direction;
    sfSprite *sprite;
    sfTexture *texture;
    int damage;
    int max_ammo;
    int ammo;
    int fire_rate;
    int reload_time;
    int reloading;
    int bullet_speed;
    sfClock *clock;
} gun_t;

gun_t *gun_create(gun_blueprint_t *blueprint);
void gun_update(gun_t *gun, sfVector2f player_pos,
    sfRenderWindow *window, sfView *view);
void gun_destroy(gun_t *gun);
void gun_shoot(gun_t *gun, game_t *game);



#endif /* !GUN_H_ */
