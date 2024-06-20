/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-florian.reynaud
** File description:
** my_hunter
*/

#ifndef DIAL_H_
    #define DIAL_H_

    #include <SFML/Graphics.h>
    #include "camera.h"
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>

    #define D_SPAWN_RATE 10000

typedef struct game_s game_t;

typedef struct conv_s {
    char *character;
    char *content;
    struct conv_s *next;
}conv_t;

typedef struct dial_s {
    sfRectangleShape* dialBox;
    sfFont* font;
    sfText* nameText;
    sfText* dialText;
    conv_t *conv;
}dial_t;

typedef struct ui_s {
    sfRenderWindow *window;
    cam_t *cam;
    dial_t *dial;
}ui_t;

typedef struct dial_spawner_s {
    sfVector2f pos;
    sfIntRect hitbox;
    int view;
    int spawn_rate;
    char *path;
}dial_spawner_t;

void create_d_spawner(game_t *game);
conv_t *open_txt_file(char *path);
void d_open_spwans(game_t *game, char *path);
void d_spawner_display(sfRenderWindow *window, dial_spawner_t *spawner);
dial_spawner_t *d_spawner_create(sfVector2f pos,
    int spawn_rate, sfVector2f size, char *path);
void d_spawner_update(dial_spawner_t *spawner, game_t *game);
void d_spawner_destroy(dial_spawner_t *spawner);

void main_dials(game_t *game);

void set_text(game_t *game);
void txt_update(sfEvent event, game_t *game);
void txt_display(sfRenderWindow *window, game_t *game);
void dial_destroy(game_t *game);

#endif /* !DIAL_H_ */
