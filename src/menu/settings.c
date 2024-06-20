/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** settings
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
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/Window.h>
#include <stdio.h>
#include <stdlib.h>

void init_settings_next(menu_t *menu)
{
    menu->maxRes->state = PRESSED;
    menu->minRes->state = NONE;
    menu->maxRes->rect = sfRectangleShape_create();
    menu->minRes->rect = sfRectangleShape_create();
    menu->maxRes->pos = (sfVector2f){450, 600};
    menu->minRes->pos = (sfVector2f){1250, 600};
    menu->maxRes->org_pos = (sfVector2f){450, 600};
    menu->minRes->org_pos = (sfVector2f){1250, 600};
    menu->maxRes->anim = (sfIntRect){250, 0, 250, 150};
    menu->minRes->anim = (sfIntRect){0, 0, 250, 150};
    menu->quit = malloc(sizeof(button_t));
    menu->quit->txt = sfTexture_createFromFile("assets/menu/quit750.png", 0);
    menu->quit->sprt = sfSprite_create();
    sfSprite_setTexture(menu->quit->sprt, menu->quit->txt, sfTrue);
    menu->quit->state = NONE;
    menu->quit->org_pos = (sfVector2f){850, 800};
    menu->quit->pos = (sfVector2f){850, 800};
    menu->quit->anim = (sfIntRect){0, 0, 250, 150};
}

settings_t *init_settings(menu_t *menu)
{
    settings_t *settings = (settings_t *)malloc(sizeof(settings_t));

    menu->maxRes = malloc(sizeof(button_t));
    menu->minRes = malloc(sizeof(button_t));
    settings->size = (sfVideoMode){1920, 1080, 32};
    settings->org_size = (sfVector2u){1920, 1080};
    settings->isFull = sfFalse;
    settings->music = 50;
    settings->sound = 50;
    menu->maxRes->txt = sfTexture_createFromFile(
        "assets/menu/1920_500.png", 0);
    menu->minRes->txt = sfTexture_createFromFile(
        "assets/menu/1280_500.png", 0);
    menu->maxRes->sprt = sfSprite_create();
    menu->minRes->sprt = sfSprite_create();
    sfSprite_setTexture(menu->maxRes->sprt, menu->maxRes->txt, sfTrue);
    sfSprite_setTexture(menu->minRes->sprt, menu->minRes->txt, sfTrue);
    init_settings_next(menu);
    return settings;
}

static void settings_update(sfEvent *event, settings_t *settings, menu_t *menu)
{
    if (menu->full->state == NONE && on_click(event, menu->full)) {
        settings->isFull = 1;
        menu->full->state = PRESSED;
        sfRenderWindow_destroy(settings->window);
        settings->window = sfRenderWindow_create(settings->size,
        "Space Breakout", sfFullscreen, 0);
        sfRenderWindow_setFramerateLimit(settings->window, 60);
        menu->full->anim.left = 375;
        return;
    }
    if (menu->full->state == PRESSED && on_click(event, menu->full)) {
        settings->isFull = 0;
        menu->full->state = NONE;
        sfRenderWindow_destroy(settings->window);
        settings->window = sfRenderWindow_create(settings->size,
        "Space Breakout", sfClose, 0);
        sfRenderWindow_setFramerateLimit(settings->window, 60);
        menu->full->anim.left = 0;
        return;
    }
}

static void settings_do_event(sfEvent event, settings_t *settings,
    menu_t *menu)
{
    while (sfRenderWindow_pollEvent(settings->window, &event)){
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(settings->window);
        button_event(menu->back, &event, menu);
        if (event.type == sfEvtMouseButtonPressed)
            settings_update(&event, settings, menu);
        check_resolution(menu, settings, &event);
    }
}

static void draw_sprites(settings_t *settings, menu_t *menu)
{
    resize_item(settings->window, menu->maxRes->sprt,
        settings->org_size, menu->maxRes->org_pos);
    sfSprite_setTextureRect(menu->maxRes->sprt, menu->maxRes->anim);
    sfRenderWindow_drawSprite(settings->window, menu->maxRes->sprt, NULL);
    resize_item(settings->window, menu->minRes->sprt,
        settings->org_size, menu->minRes->org_pos);
    sfSprite_setTextureRect(menu->minRes->sprt, menu->minRes->anim);
    sfRenderWindow_drawSprite(settings->window, menu->minRes->sprt, NULL);
    resize_item(settings->window, menu->back->sprt,
        settings->org_size, menu->back->org_pos);
    sfSprite_setTextureRect(menu->back->sprt, menu->back->anim);
    sfRenderWindow_drawSprite(settings->window,
        menu->back->sprt, NULL);
    resize_item(settings->window, menu->full->sprt,
        settings->org_size, menu->full->org_pos);
    sfSprite_setTextureRect(menu->full->sprt, menu->full->anim);
    sfRenderWindow_drawSprite(settings->window, menu->full->sprt, NULL);
}

static void settings_display(sfEvent event, settings_t *settings, menu_t *menu)
{
    sfVector2u windowSize = sfRenderWindow_getSize(settings->window);
    sfVector2u textureSize = sfTexture_getSize(menu->bg_txt);
    float scaleX = (float)windowSize.x / textureSize.x;
    float scaleY = (float)windowSize.y / textureSize.y;

    sfRenderWindow_clear(settings->window, sfBlack);
    sfSprite_setScale(menu->bg_sprt, (sfVector2f){scaleX, scaleY});
    sfSprite_setScale(menu->load_sprt, (sfVector2f){scaleX, scaleY});
    sfRenderWindow_drawSprite(settings->window, menu->bg_sprt, NULL);
    draw_sprites(settings, menu);
    sfRenderWindow_display(settings->window);
}

static void do_settings(settings_t *settings, sfEvent event, menu_t *menu)
{
    settings_do_event(event, settings, menu);
    settings_display(event, settings, menu);
}

void settings_loop(settings_t *settings, sfEvent event, menu_t *menu)
{
    while (sfRenderWindow_isOpen(settings->window)) {
        do_settings(settings, event, menu);
        if (menu->back->state == PRESSED) {
            menu->back->state = NONE;
            break;
        }
    }
}
