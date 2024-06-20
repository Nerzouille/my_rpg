/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-florian.reynaud
** File description:
** my_hunter
*/

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_

    #include "menu.h"
    #include "game.h"
    #include "camera.h"
    #include "mylist.h"
    #include "player.h"
    #include "bullet.h"
    #include "menu.h"
    #include <SFML/Config.h>
    #include "obstacle.h"
    #include "inventory.h"
    #include "gun.h"
    #include "mobs.h"
    #include "utils.h"
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Window/VideoMode.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <math.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>

    #define XP_GAIN 10

enum scene {
    NO_SCENE = 0,
    MENU,
    GAME
};

typedef struct app_s {
    sfRenderWindow *window;
    sfEvent event;
    menu_t *menu;
    game_t *game;
    settings_t *settings;
    enum scene scene;
}app_t;

app_t *app_create(void);
void app_loop(app_t *app);
void app_switch_to_game(app_t *app);
void app_switch_to_menu(app_t *app);
void app_destroy(app_t *app);
void disp_hitbox(game_t *game, sfRenderWindow *window);


#endif /* !MY_HUNTER_H_ */
