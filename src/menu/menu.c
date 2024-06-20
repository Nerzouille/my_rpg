/*
** EPITECH PROJECT, 2024
** main_game
** File description:
** menu
*/

#include "../../include/my_rpg.h"
#include <SFML/Config.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderTexture.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>
#include <stdio.h>
#include <stdlib.h>

static void def_bg(menu_t *menu)
{
    menu->bg_txt = sfTexture_createFromFile("assets/menu/bg.png", 0);
    menu->load_txt = sfTexture_createFromFile("assets/menu/loading.png", 0);
    menu->start->txt = sfTexture_createFromFile("assets/menu/start750.png", 0);
    menu->opts->txt = sfTexture_createFromFile("assets/menu/option750.png", 0);
    menu->bg_sprt = sfSprite_create();
    menu->load_sprt = sfSprite_create();
    menu->start->sprt = sfSprite_create();
    menu->opts->sprt = sfSprite_create();
    sfSprite_setTexture(menu->bg_sprt, menu->bg_txt, sfFalse);
    sfSprite_setTexture(menu->load_sprt, menu->load_txt, sfFalse);
    sfSprite_setTexture(menu->start->sprt, menu->start->txt, sfTrue);
    sfSprite_setTexture(menu->opts->sprt, menu->opts->txt, sfTrue);
}

menu_t *menu_create(app_t *app)
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu->load = 0;
    menu->opts = malloc(sizeof(button_t));
    menu->start = malloc(sizeof(button_t));
    menu->back = malloc(sizeof(button_t));
    menu->full = malloc(sizeof(button_t));
    def_bg(menu);
    menu->start->state = NONE;
    menu->opts->state = NONE;
    menu->start->rect = sfRectangleShape_create();
    menu->opts->rect = sfRectangleShape_create();
    menu->app = app;
    return menu;
}

static void save_origin(menu_t *menu)
{
    menu->start->org_pos = (sfVector2f){850, 400};
    menu->opts->org_pos = (sfVector2f){850, 600};
    menu->back->org_pos = (sfVector2f){200, 900};
    menu->full->org_pos = (sfVector2f){800, 400};
    menu->buffer_button =
        sfSoundBuffer_createFromFile("assets/sound/button_click.ogg");
    menu->sound_button = sfSound_create();
    sfSound_setBuffer(menu->sound_button, menu->buffer_button);
    sfSound_setVolume(menu->sound_button, 300.0f);
}

void init_button(menu_t *menu)
{
    menu->back->txt = sfTexture_createFromFile("assets/menu/back750.png", 0);
    menu->back->sprt = sfSprite_create();
    sfSprite_setTexture(menu->back->sprt, menu->back->txt, sfTrue);
    menu->back->state = NONE;
    menu->back->rect = sfRectangleShape_create();
    menu->full->txt = sfTexture_createFromFile("assets/menu/full750.png", 0);
    menu->full->sprt = sfSprite_create();
    sfSprite_setTexture(menu->full->sprt, menu->full->txt, sfTrue);
    menu->full->state = NONE;
    menu->full->rect = sfRectangleShape_create();
    menu->start->pos = (sfVector2f){850, 400};
    menu->opts->pos = (sfVector2f){850, 600};
    menu->back->pos = (sfVector2f){200, 900};
    menu->full->pos = (sfVector2f){800, 400};
    menu->start->anim = (sfIntRect){0, 0, 250, 150};
    menu->opts->anim = (sfIntRect){0, 0, 250, 150};
    menu->back->anim = (sfIntRect){0, 0, 250, 150};
    menu->full->anim = (sfIntRect){0, 0, 375, 150};
    save_origin(menu);
}

static void menu_do_event(sfEvent event, menu_t *menu,
    settings_t *settigs)
{
    while (sfRenderWindow_pollEvent(settigs->window, &event)){
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(settigs->window);
        button_event(menu->start, &event, menu);
        button_event(menu->opts, &event, menu);
        button_event(menu->quit, &event, menu);
        check_click(menu, settigs, event);
    }
}

static void draw_sprite(menu_t *menu, settings_t *settings)
{
    resize_item(settings->window, menu->start->sprt,
        settings->org_size, menu->start->org_pos);
    sfSprite_setTextureRect(menu->start->sprt, menu->start->anim);
    sfRenderWindow_drawSprite(settings->window, menu->start->sprt, NULL);
    resize_item(settings->window, menu->opts->sprt,
        settings->org_size, menu->opts->org_pos);
    sfSprite_setTextureRect(menu->opts->sprt, menu->opts->anim);
    sfRenderWindow_drawSprite(settings->window, menu->opts->sprt, NULL);
    resize_item(settings->window, menu->quit->sprt,
        settings->org_size, menu->quit->org_pos);
    sfSprite_setTextureRect(menu->quit->sprt, menu->quit->anim);
    sfRenderWindow_drawSprite(settings->window, menu->quit->sprt, NULL);
}

void menu_display(menu_t *menu, settings_t *settings)
{
    sfRenderWindow_clear(settings->window, sfBlack);
    sfRenderWindow_drawSprite(settings->window, menu->bg_sprt, NULL);
    draw_sprite(menu, settings);
    if (menu->load == 1)
        sfRenderWindow_drawSprite(settings->window, menu->load_sprt, NULL);
    sfRenderWindow_display(settings->window);
}

static void menu_update(menu_t *menu)
{
    return;
}

void menu_loop(menu_t *menu, sfEvent event, settings_t *settings)
{
    menu_do_event(event, menu, settings);
    menu_update(menu);
    menu_display(menu, settings);
}

void menu_destroy(menu_t *menu)
{
    sfSprite_destroy(menu->load_sprt);
    sfTexture_destroy(menu->load_txt);
    free(menu);
}
