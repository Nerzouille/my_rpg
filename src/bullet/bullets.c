/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** bullets
*/

#include "../../include/my_rpg.h"
#include <SFML/Config.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Types.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stdlib.h>

static void bullet_create_sprite(bullet_t *bullet)
{
    if (bullet->sprite != NULL){
        sfSprite_destroy(bullet->sprite);
        bullet->sprite = NULL;
    }
    if (bullet->texture != NULL){
        sfTexture_destroy(bullet->texture);
        bullet->texture = NULL;
    }
    if (bullet->type == PLAYER_BULLET)
        bullet->texture = sfTexture_createFromFile("assets/bullet.png", NULL);
    else
        bullet->texture = sfTexture_createFromFile("assets/bullet_slime.png",
            NULL);
    bullet->texture_rect = (sfIntRect){0, 0, BULLET_TEXTURE_WIDTH,
        BULLET_TEXTURE_HEIGHT};
    bullet->sprite = sfSprite_create();
    sfSprite_setTexture(bullet->sprite, bullet->texture, sfFalse);
    sfSprite_setPosition(bullet->sprite, bullet->pos);
    sfSprite_setTextureRect(bullet->sprite, bullet->texture_rect);
}

bullet_t *bullet_create(sfVector2f pos, sfVector2f direction, int speed,
    int damage)
{
    bullet_t *bullet;

    bullet = malloc(sizeof(bullet_t));
    bullet->pos = pos;
    bullet->sprite = NULL;
    bullet->texture = NULL;
    bullet->hitbox = (sfIntRect){pos.x, pos.y,
        BULLET_TEXTURE_WIDTH, BULLET_TEXTURE_HEIGHT};
    bullet->direction = direction;
    bullet->speed = speed;
    bullet->damage = damage;
    bullet->clock = sfClock_create();
    bullet->type = PLAYER_BULLET;
    bullet->id = 0;
    bullet->destroy = 0;
    bullet->texture_clock = sfClock_create();
    bullet_create_sprite(bullet);
    return bullet;
}

void set_bullet_type(bullet_t *bullet, enum bullet_type type)
{
    bullet->type = type;
    bullet_create_sprite(bullet);
}

static void set_bullet_texture_rect(bullet_t *bullet)
{
    int time = sfClock_getElapsedTime(bullet->texture_clock).microseconds;

    if (time < 50000)
        return;
    if (bullet->texture_rect.left >= BULLET_TEXTURE_WIDTH * 6)
        bullet->texture_rect.left = 0;
    else
        bullet->texture_rect.left += BULLET_TEXTURE_WIDTH;
    sfSprite_setTextureRect(bullet->sprite, bullet->texture_rect);
    sfClock_restart(bullet->texture_clock);
}

void bullet_update(bullet_t *bullet)
{
    int time;

    bullet->pos.x += bullet->direction.x * bullet->speed;
    bullet->pos.y += bullet->direction.y * bullet->speed;
    sfSprite_setPosition(bullet->sprite, bullet->pos);
    bullet->hitbox = (sfIntRect){bullet->pos.x, bullet->pos.y, 10, 10};
    time = sfClock_getElapsedTime(bullet->clock).microseconds;
    set_bullet_texture_rect(bullet);
    if (time >= MAX_BULLET_TIME)
        bullet->destroy = 1;
}

void bullet_display(bullet_t *bullet, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, bullet->sprite, NULL);
}

void bullet_destroy(bullet_t *bullet)
{
    sfSprite_destroy(bullet->sprite);
    sfTexture_destroy(bullet->texture);
    sfClock_destroy(bullet->clock);
    sfClock_destroy(bullet->texture_clock);
    free(bullet);
}
