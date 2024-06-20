/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** mobs
*/

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Types.h>
#include <SFML/System/Vector2.h>
#include "utils.h"

#ifndef MOBS_H_
    #define MOBS_H_

    #define MOB_TEXTURE_WIDTH 32
    #define MOB_TEXTURE_HEIGHT 32
    #define MOB_TOTAL_WIDTH 64
    #define MOB_TOTAL_HEIGHT 64
    #define MOB_HP 30
    #define MOB_DAMAGE 20
    #define SPAWN_RATE 10000
    #define LEVEL_RATIO(level) 1 + (level * (1 / 10))

typedef struct game_s game_t;
typedef struct mob_s mob_t;

typedef struct mob_spawner_s {
    sfClock *clock;
    sfVector2f pos;
    sfIntRect hitbox;
    sfVector2f *mob_positions;
    sfBool can_spawn;
    int mob_count;
    int spawn_rate;
}mob_spawner_t;

mob_spawner_t *spawner_create(sfVector2f pos, int spawn_rate, sfVector2f size);
void spawner_set_mob_positions(mob_spawner_t *spawner, sfVector2f *positions,
    int nb_mob);
void spawner_displaye(sfRenderWindow *window, mob_spawner_t *spawner);
void spawner_update(mob_spawner_t *spawner, game_t *game);
void spawner_destroy(mob_spawner_t *spawner);

typedef struct mob_list_s {
    struct mob_s *mob;
    struct mob_list_s *next;
}mob_list_t;

mob_list_t *add_mob_to_mob_list(mob_list_t *list,
    mob_t *mob);
void mob_list_display(mob_list_t *list, sfRenderWindow *window);
void mob_list_destroy(mob_list_t *list);
mob_list_t *mob_list_update(mob_list_t *list, sfRenderWindow *window,
    game_t *game);

typedef struct mob_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect texture_rect;
    sfIntRect hitbox;
    sfClock *texture_clock;
    sfVector2f pos;
    sfVector2f last_pos;
    sfVector2f direction;
    sfClock *shoot_clock;
    health_bar_t *health_bar;
    int speed;
    int alive;
    int health;
    int health_max;
}mob_t;

void open_spwans(game_t *game, char *path);
mob_t *mob_create(sfVector2f pos, game_t *game);
void mob_update(mob_t *mob, sfRenderWindow *window, game_t *game);
void mob_set_position(mob_t *mob, sfVector2f pos);
void mob_display(mob_t *mob, sfRenderWindow *window);
void mob_destroy(mob_t *mob);

#endif /* !MOBS_H_ */
