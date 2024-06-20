/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_

    #include "my.h"
    #include "map.h"
    #include "camera.h"
    #include "mylist.h"
    #include "player.h"
    #include "bullet.h"
    #include "obstacle.h"
    #include "inventory.h"
    #include "menu.h"
    #include "dial.h"

typedef struct app_s app_t;

typedef struct game_s {
    int freeze_game;
    int didacticiel;
    sfMusic* mus_tuto;
    sfMusic* mus_game;
    sfMusic* mus_end;
    map_t *map;
    player_t *player;
    cam_t *cam;
    ui_t *ui;
    bullet_list_t *bullet_list;
    obstacle_list_t *obstacle_list;
    mob_list_t *mob_list;
    mob_spawner_t **spawners;
    dial_spawner_t **d_spawners;
    int nb_spawner;
    int nb_d_spawner;
    inventory_t *inventory;
    health_bar_t *health_bar;
    xp_bar_t *xp_bar;
    sfRenderWindow *window;
    app_t *app;
    sfSoundBuffer* buffer_button;
    sfSound* sound_button;
    sfTexture *pau_txt;
    sfSprite *pau_sprt;
    button_t *res;
    button_t *opts;
    button_t *menu;
    int isPause;
}game_t;

int do_game(settings_t *settings, sfEvent event);
game_t *game_create(sfRenderWindow *window, app_t *app);
game_t *create_pause(game_t *game);
void game_loop(game_t *game, menu_t *menu,
    sfEvent event, settings_t *settings);
void game_display(game_t *game, sfRenderWindow *window,
    settings_t *settings, sfEvent event);
void game_destroy(game_t *game);

void player_handle_shoot(player_t *player, game_t *game);

health_bar_t *game_health_bar_create(game_t *game);
void game_health_bar_update(game_t *game);
void button_event_view(button_t *button, sfEvent *event,
    sfView *view, sfRenderWindow *window);
void pause_display(game_t *game, settings_t *settings);
void check_button_pressed(game_t *game, sfEvent *event,
    settings_t *settings, menu_t *menu);

xp_bar_t *game_xp_bar_create(game_t *game);
void game_xp_bar_update(game_t *game);

void def_songs(game_t *game);
void dest_songs(game_t *game);


#endif /* !GAME_H_ */
