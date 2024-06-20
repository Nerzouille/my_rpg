/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** utils
*/
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RenderWindow.h>

#ifndef UTILS_H_
    #define UTILS_H_

typedef struct health_bar_s {
    sfRectangleShape *bar;
    sfRectangleShape *bg;
    sfVector2f pos;
    sfVector2f size;
    sfVector2f bg_size;
    int health;
    int health_max;
}health_bar_t;

health_bar_t *health_bar_create(sfVector2f pos, sfVector2f size,
    int health, int health_max);
void health_bar_update(health_bar_t *health_bar, sfVector2f pos, int health,
    int health_max);
void health_bar_display(health_bar_t *health_bar, sfRenderWindow *window);
void health_bar_destroy(health_bar_t *health_bar);

typedef struct xp_bar_s {
    sfRectangleShape *bar;
    sfRectangleShape *bg;
    sfVector2f pos;
    sfVector2f size;
    sfVector2f bg_size;
    int xp;
    int xp_max;
}xp_bar_t;

xp_bar_t *xp_bar_create(sfVector2f pos, sfVector2f size,
    int xp, int xp_max);
void xp_bar_update(xp_bar_t *xp_bar, sfVector2f pos, int xp);
void xp_bar_display(xp_bar_t *xp_bar, sfRenderWindow *window);
void xp_bar_destroy(xp_bar_t *xp_bar);

sfVector2f vector_normalize(sfVector2f vector);
float vector_get_angle(sfVector2f vector);
int vector_get_distance(sfVector2f vector1, sfVector2f vector2);
int check_collision(sfIntRect rect1, sfIntRect rect2);
void display_hitbox(sfIntRect hitbox, sfRenderWindow *window);

#endif /* !UTILS_H_ */
