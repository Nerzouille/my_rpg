/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** game
*/

#include "../include/my_rpg.h"
#include "../include/map.h"
#include "../include/utils.h"
#include "../include/dial.h"
#include <SFML/Window/Event.h>
#include <stdio.h>

static void game_create_spawner(game_t *game)
{
    sfVector2f *positions = malloc(sizeof(sfVector2f) * 2);

    game->buffer_button =
        sfSoundBuffer_createFromFile("assets/sound/button_click.ogg");
    game->sound_button = sfSound_create();
    sfSound_setBuffer(game->sound_button, game->buffer_button);
    sfSound_setVolume(game->sound_button, 300.0f);
    game->spawners = malloc(sizeof(mob_spawner_t) * 28);
    game->nb_spawner = 27;
    game->spawners[0] = spawner_create((sfVector2f){4128, 6576},
    SPAWN_RATE, (sfVector2f){288, 192});
    positions[0] = (sfVector2f){4032, 6624};
    positions[1] = (sfVector2f){4416, 6768};
    spawner_set_mob_positions(game->spawners[0], positions, 2);
    open_spwans(game, "assets/csv/spawners.txt");
    create_d_spawner(game);
    d_open_spwans(game, "assets/csv/dial.txt");
}

static void game_create_step(game_t *game, sfRenderWindow *window, app_t *app)
{
    def_songs(game);
    def_collide(game, game->map);
    set_text(game);
    create_doors_s(game);
    game->app = app;
    open_save(game);
}

game_t *game_create(sfRenderWindow *window, app_t *app)
{
    game_t *game = malloc(sizeof(game_t));

    game->map = gen_map();
    game->player = player_create((sfVector2f){4100, 6500});
    game->cam = camera_create(window, 2);
    game->inventory = create_inv();
    game->bullet_list = NULL;
    game->obstacle_list = NULL;
    game->mob_list = NULL;
    game->spawners = NULL;
    game->health_bar = game_health_bar_create(game);
    game->xp_bar = game_xp_bar_create(game);
    game = create_pause(game);
    game_create_spawner(game);
    game_create_step(game, window, app);
    return game;
}

static void game_do_event(settings_t *settings, sfEvent event,
    game_t *game, menu_t *menu)
{
    while (sfRenderWindow_pollEvent(settings->window, &event)){
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(settings->window);
        check_button_pressed(game, &event, settings, menu);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        game->isPause = 1;
    }
    txt_update(event, game);
    player_handle_input(game->player, game, settings->window);
    handle_event_inv(game, settings->window);
}

static void game_handle_pause(game_t *game, sfRenderWindow *window,
    settings_t *settings)
{
    if (game->isPause == 1)
        pause_display(game, settings);
    if (!game->freeze_game)
        health_bar_display(game->health_bar, window);
}

void game_display(game_t *game, sfRenderWindow *window,
    settings_t *settings, sfEvent event)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/8-bit.ttf");

    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_setView(window, game->cam->view);
    map_display(game, window);
    player_display(game->player, window);
    parralax(window, game);
    mob_list_display(game->mob_list, window);
    display_bullet_list(game->bullet_list, window);
    tiles_disp(window, game->map->doors);
    txt_display(window, game);
    if (game->inventory->is_open == 1 && game->freeze_game == 0) {
        render_inventory(game, game->inventory, window);
        render_all_slot(game, game->inventory, window);
    }
    xp_bar_display(game->xp_bar, window);
    game_handle_pause(game, window, settings);
    sfRenderWindow_display(window);
}

static void game_change_player_gun(game_t *game)
{
    if (game->inventory->weapon_slot == NULL){
        if (game->player->gun != NULL)
            gun_destroy(game->player->gun);
        game->player->gun = NULL;
        return;
    }
    if (game->player->gun != NULL)
        if (my_strcmp(game->player->gun->name,
            game->inventory->weapon_slot) == 0)
            return;
    if (game->player->gun != NULL)
        gun_destroy(game->player->gun);
    game->player->gun = gun_create(
        get_gun_blueprint(game->inventory->weapon_slot));
}

static void game_update(game_t *game, sfRenderWindow *window)
{
    game_change_player_gun(game);
    player_update(game, game->player, window, game->cam->view);
    check_collision_player_obstacle(game->player, game->obstacle_list);
    camera_update(game->cam, game->player->pos, window);
    if (game->freeze_game == 0) {
        game->bullet_list = update_bullet_list(game->bullet_list);
        game->mob_list = mob_list_update(game->mob_list, window, game);
    }
    check_collision_bullet_mob(game);
    check_collision_bullet_obstacle(game);
    check_collision_bullet_player(game);
    for (int i = 0; i < game->nb_spawner; i++)
        spawner_update(game->spawners[i], game);
    for (int i = 0; i < game->nb_d_spawner; i++)
        d_spawner_update(game->d_spawners[i], game);
    doors_update(game);
    game_health_bar_update(game);
    game_xp_bar_update(game);
    update_doors_s(game);
}

static void game_restart(game_t *game)
{
    player_destroy(game->player);
    game->player = player_create((sfVector2f){4100, 6500});
    mob_list_destroy(game->mob_list);
    game->mob_list = NULL;
}

void game_loop(game_t *game, menu_t *menu,
    sfEvent event, settings_t *settings)
{
    game_do_event(settings, event, game, menu);
    game_update(game, settings->window);
    game_display(game, settings->window, settings, event);
    if (!game->player->alive &&
        sfClock_getElapsedTime(game->player->death_clock).microseconds
            > 3000000){
        game_restart(game);
    }
}
