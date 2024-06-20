/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** buttons
*/

#include "../../include/my_rpg.h"
#include <SFML/Config.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RenderTexture.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <stdio.h>
#include <stdlib.h>

sfBool is_hover(sfEvent *event, button_t *button)
{
    sfVector2i mouse = sfMouse_getPosition(NULL);
    sfFloatRect spriteBounds = sfSprite_getGlobalBounds(button->sprt);

    if (sfFloatRect_contains(&spriteBounds, mouse.x, mouse.y)) {
        button->state = HOVER;
        return sfTrue;
    }
    return sfFalse;
}

sfBool on_click(sfEvent *event, button_t *button)
{
    sfVector2i mouse;
    sfFloatRect spriteBounds = sfSprite_getGlobalBounds(button->sprt);

    mouse.x = event->mouseButton.x;
    mouse.y = event->mouseButton.y;
    if (sfFloatRect_contains(&spriteBounds, mouse.x, mouse.y)) {
        button->state = PRESSED;
        return sfTrue;
    }
    return sfFalse;
}

void check_click(menu_t *menu, settings_t *settings, sfEvent event)
{
    if (menu->start->state == PRESSED) {
        app_switch_to_game(menu->app);
    }
    if (menu->opts->state == PRESSED) {
        settings_loop(settings, event, menu);
    }
    if (menu->quit->state == PRESSED) {
        sfRenderWindow_close(settings->window);
    }
}

void button_event(button_t *button, sfEvent *event, menu_t *menu)
{
    if (button->state == PRESSED)
        button->state = NONE;
    if (event->type == sfEvtMouseMoved) {
        if (is_hover(event, button)){
            button->anim.left = 250;
        } else {
            button->state = NONE;
            button->anim.left = 0;
        }
    }
    if (event->type == sfEvtMouseButtonPressed) {
        if (on_click(event, button)) {
            sfSound_play(menu->sound_button);
            button->anim.left = 500;
        }
    }
}
