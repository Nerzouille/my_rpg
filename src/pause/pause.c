/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** pause
*/

#include "../../include/my_rpg.h"

#include <SFML/Config.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/View.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stdlib.h>

static void pause_next(game_t *game)
{
    game->res->state = NONE;
    game->opts->state = NONE;
    game->menu->state = NONE;
    game->res->anim = (sfIntRect){0, 0, 250, 40};
    game->opts->anim = (sfIntRect){0, 0, 250, 40};
    game->menu->anim = (sfIntRect){0, 0, 250, 40};
}

static void actions_on_click(game_t *game, settings_t *settings,
    sfEvent event, menu_t *menu)
{
    if (game->res->state == PRESSED) {
        game->isPause = 0;
        game->freeze_game = 0;
    }
    if (game->menu->state == PRESSED) {
        sfRenderWindow_destroy(settings->window);
        exit(0);
    }
}

void check_button_pressed(game_t *game, sfEvent *event,
    settings_t *settings, menu_t *menu)
{
    button_event_view(game->res, event,
        game->cam->view, settings->window);
    button_event_view(game->menu, event,
        game->cam->view, settings->window);
    button_event_view(game->opts, event,
        game->cam->view, settings->window);
    actions_on_click(game, settings, *event, menu);
}

game_t *create_pause(game_t *game)
{
    game->res = malloc(sizeof(button_t));
    game->opts = malloc(sizeof(button_t));
    game->menu = malloc(sizeof(button_t));
    game->pau_txt = sfTexture_createFromFile("assets/pause/pause.png", NULL);
    game->pau_sprt = sfSprite_create();
    game->res->txt = sfTexture_createFromFile(
        "assets/pause/resume_750.png", 0);
    game->opts->txt = sfTexture_createFromFile("assets/pause/opts_750.png", 0);
    game->menu->txt = sfTexture_createFromFile("assets/pause/menu_750.png", 0);
    game->res->sprt = sfSprite_create();
    game->opts->sprt = sfSprite_create();
    game->menu->sprt = sfSprite_create();
    sfSprite_setTexture(game->res->sprt, game->res->txt, sfTrue);
    sfSprite_setTexture(game->opts->sprt, game->opts->txt, sfTrue);
    sfSprite_setTexture(game->menu->sprt, game->menu->txt, sfTrue);
    game->res->rect = sfRectangleShape_create();
    game->opts->rect = sfRectangleShape_create();
    game->menu->rect = sfRectangleShape_create();
    pause_next(game);
    return game;
}

static void set_pos_pause(game_t *game)
{
    sfSprite_setScale(game->pau_sprt, (sfVector2f)
        {sfView_getSize(game->cam->view).x / 450,
        sfView_getSize(game->cam->view).y / 195});
    sfSprite_setPosition(game->pau_sprt, (sfVector2f)
        {sfView_getCenter(game->cam->view).x - 175,
        sfView_getCenter(game->cam->view).y - 180});
    sfSprite_setPosition(game->res->sprt, (sfVector2f)
        {sfView_getCenter(game->cam->view).x - 100,
        sfView_getCenter(game->cam->view).y - 110});
    sfSprite_setPosition(game->opts->sprt, (sfVector2f)
        {sfView_getCenter(game->cam->view).x - 100,
            sfView_getCenter(game->cam->view).y - 30});
    sfSprite_setPosition(game->menu->sprt, (sfVector2f)
        {sfView_getCenter(game->cam->view).x - 100,
        sfView_getCenter(game->cam->view).y + 50});
}

void pause_display(game_t *game, settings_t *settings)
{
    sfSprite_setTexture(game->pau_sprt, game->pau_txt, sfTrue);
    sfSprite_setTexture(game->res->sprt, game->res->txt, sfTrue);
    sfSprite_setTexture(game->opts->sprt, game->opts->txt, sfTrue);
    sfSprite_setTexture(game->menu->sprt, game->menu->txt, sfTrue);
    set_pos_pause(game);
    sfSprite_setTextureRect(game->res->sprt, game->res->anim);
    sfSprite_setTextureRect(game->opts->sprt, game->opts->anim);
    sfSprite_setTextureRect(game->menu->sprt, game->menu->anim);
    sfRenderWindow_drawSprite(settings->window, game->pau_sprt, NULL);
    sfRenderWindow_drawSprite(settings->window, game->res->sprt, NULL);
    sfRenderWindow_drawSprite(settings->window, game->opts->sprt, NULL);
    sfRenderWindow_drawSprite(settings->window, game->menu->sprt, NULL);
}
