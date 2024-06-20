/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** utils
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Vector2.h>
#include <math.h>

sfVector2f vector_normalize(sfVector2f vector)
{
    float magnitude = sqrt(vector.x * vector.x + vector.y * vector.y);

    if (magnitude != 0.0f) {
        vector.x /= magnitude;
        vector.y /= magnitude;
    }
    return vector;
}

float vector_get_angle(sfVector2f vector)
{
    return atan2(vector.y, vector.x) * 180 / M_PI;
}

int vector_get_distance(sfVector2f vector1, sfVector2f vector2)
{
    float dx = vector2.x - vector1.x;
    float dy = vector2.y - vector1.y;
    float distance = sqrt(dx * dx + dy * dy);

    return (int)distance;
}

int check_collision(sfIntRect rect1, sfIntRect rect2)
{
    if (rect1.left < rect2.left + rect2.width &&
        rect1.left + rect1.width > rect2.left &&
        rect1.top < rect2.top + rect2.height &&
        rect1.top + rect1.height > rect2.top)
        return 1;
    return 0;
}

void display_hitbox(sfIntRect hitbox, sfRenderWindow *window)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setSize(shape, (sfVector2f){hitbox.width, hitbox.height});
    sfRectangleShape_setPosition(shape, (sfVector2f){hitbox.left, hitbox.top});
    sfRectangleShape_setFillColor(shape, sfTransparent);
    sfRectangleShape_setOutlineColor(shape, sfRed);
    sfRectangleShape_setOutlineThickness(shape, 1);
    sfRenderWindow_drawRectangleShape(window, shape, NULL);
    sfRectangleShape_destroy(shape);
}
