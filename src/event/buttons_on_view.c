/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** buttons_on_view
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

sfBool is_hover_view(sfEvent *event, button_t *button,
    sfView *view, sfRenderWindow *window)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(window);
    sfVector2f worldPos = sfRenderWindow_mapPixelToCoords(window,
        pixelPos, view);
    sfFloatRect spriteBounds = sfSprite_getGlobalBounds(button->sprt);

    if (sfFloatRect_contains(&spriteBounds, worldPos.x, worldPos.y)) {
        button->state = HOVER;
        return sfTrue;
    }
    return sfFalse;
}

sfBool on_click_view(sfEvent *event, button_t *button,
    sfView *view, sfRenderWindow *window)
{
    sfVector2i pixelPos = {event->mouseButton.x, event->mouseButton.y};
    sfVector2f worldPos = sfRenderWindow_mapPixelToCoords(window,
        pixelPos, view);
    sfFloatRect spriteBounds = sfSprite_getGlobalBounds(button->sprt);

    if (sfFloatRect_contains(&spriteBounds, worldPos.x, worldPos.y)) {
        button->state = PRESSED;
        return sfTrue;
    }
    return sfFalse;
}

void button_event_view(button_t *button, sfEvent *event,
    sfView *view, sfRenderWindow *window)
{
    if (button->state == PRESSED)
        button->state = NONE;
    if (event->type == sfEvtMouseMoved) {
        if (is_hover_view(event, button, view, window)){
            button->anim.left = 250;
        } else {
            button->state = NONE;
            button->anim.left = 0;
        }
    }
    if (event->type == sfEvtMouseButtonPressed) {
        if (on_click_view(event, button, view, window)) {
            button->anim.left = 500;
        }
    }
}
