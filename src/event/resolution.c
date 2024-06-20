/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** resolution
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
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/Window.h>

static void change_resolution(settings_t *settings, menu_t *menu)
{
    if (settings->isFull == 0) {
        sfRenderWindow_destroy(settings->window);
        settings->window = sfRenderWindow_create(settings->size,
        "Space Breakout", sfClose, 0);
        sfRenderWindow_setFramerateLimit(settings->window, 60);
    } else {
        sfRenderWindow_destroy(settings->window);
        settings->window = sfRenderWindow_create(settings->size,
        "Space Breakout", sfFullscreen, 0);
        sfRenderWindow_setFramerateLimit(settings->window, 60);
    }
}

void check_resolution(menu_t *menu, settings_t *settings, sfEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed) {
        if (menu->minRes->state == NONE && on_click(event, menu->minRes)) {
            menu->minRes->state = PRESSED;
            menu->maxRes->state = NONE;
            menu->minRes->anim.left = 250;
            menu->maxRes->anim.left = 0;
            settings->size = (sfVideoMode){1280, 720, 32};
            change_resolution(settings, menu);
            return;
        }
        if (menu->maxRes->state == NONE && on_click(event, menu->maxRes)) {
            menu->maxRes->state = PRESSED;
            menu->minRes->state = NONE;
            menu->maxRes->anim.left = 250;
            menu->minRes->anim.left = 0;
            settings->size = (sfVideoMode){1920, 1080, 32};
            change_resolution(settings, menu);
            return;
        }
    }
}

void resize_item(sfRenderWindow *window, sfSprite *sprite,
    sfVector2u orgWin, sfVector2f orgBut)
{
    sfVector2u winSize = sfRenderWindow_getSize(window);
    float scaleX = (float)winSize.x / orgWin.x;
    float scaleY = (float)winSize.y / orgWin.y;

    sfSprite_setScale(sprite, (sfVector2f){scaleX, scaleY});
    sfSprite_setPosition(sprite, (sfVector2f){orgBut.x * scaleX,
        orgBut.y * scaleY});
}
