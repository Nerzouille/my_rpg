/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** app
*/

#include "../include/my_rpg.h"
#include <stdio.h>

app_t *app_create(void)
{
    app_t *app = malloc(sizeof(app_t));

    app->menu = menu_create(app);
    app->settings = init_settings(app->menu);
    app->settings->window = sfRenderWindow_create(app->settings->size,
    "Space Breakout", sfClose, 0);
    sfRenderWindow_setFramerateLimit(app->settings->window, 60);
    init_button(app->menu);
    app->game = NULL;
    app->scene = MENU;
    return app;
}

void app_loop(app_t *app)
{
    while (sfRenderWindow_isOpen(app->settings->window)) {
        switch (app->scene) {
            case MENU:
                menu_loop(app->menu, app->event, app->settings);
                break;
            case GAME:
                game_loop(app->game, app->menu, app->event, app->settings);
                break;
            default:
                return;
        }
    }
}

void app_switch_to_game(app_t *app)
{
    if (app->game)
        game_destroy(app->game);
    app->menu->load = 1;
    menu_display(app->menu, app->settings);
    app->game = game_create(app->settings->window, app);
    app->game->window = app->settings->window;
    app->menu->load = 0;
    app->scene = GAME;
}

void app_switch_to_menu(app_t *app)
{
    if (app->menu)
        menu_destroy(app->menu);
    app->menu = menu_create(app);
    init_button(app->menu);
    app->scene = MENU;
}

void app_destroy(app_t *app)
{
    if (app->menu != NULL)
        menu_destroy(app->menu);
    if (app->game != NULL)
        game_destroy(app->game);
    sfRenderWindow_destroy(app->settings->window);
    free(app->settings);
    free(app);
}
