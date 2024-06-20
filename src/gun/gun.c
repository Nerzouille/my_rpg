/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** gun
*/

#include "../../include/my_rpg.h"
#include <SFML/Config.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Types.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../include/utils.h"

static void gun_create_sprite(gun_t *gun, gun_blueprint_t *blueprint)
{
    sfVector2u size;
    sfVector2f origin;

    my_strcpy(gun->name, blueprint->name);
    gun->sprite = sfSprite_create();
    gun->texture = sfTexture_createFromFile(blueprint->texture_path, NULL);
    sfSprite_setTexture(gun->sprite, gun->texture, sfTrue);
    size = sfTexture_getSize(gun->texture);
    origin = (sfVector2f){(float)size.x / 2, (float)size.y / 2};
    sfSprite_setOrigin(gun->sprite, origin);
}

gun_t *gun_create(gun_blueprint_t *blueprint)
{
    gun_t *gun = malloc(sizeof(gun_t));

    gun->ammo = blueprint->max_ammo;
    gun->max_ammo = blueprint->max_ammo;
    gun->damage = blueprint->damage;
    gun->fire_rate = blueprint->fire_rate;
    gun->reload_time = blueprint->reload_time;
    gun->bullet_speed = blueprint->bullet_speed;
    gun->reloading = 0;
    gun->clock = sfClock_create();
    gun_create_sprite(gun, blueprint);
    return gun;
}

static void gun_update_direction(gun_t *gun, sfVector2f pos,
    sfView *view, sfRenderWindow *window)
{
    sfVector2i pixelPos = sfMouse_getPositionRenderWindow(
        window);
    sfVector2f worldPos = sfRenderWindow_mapPixelToCoords(
        window, pixelPos, view);
    sfVector2f mouse_pos = (sfVector2f){worldPos.x, worldPos.y};

    gun->direction.x = mouse_pos.x - pos.x;
    gun->direction.y = mouse_pos.y - pos.y;
    gun->direction = vector_normalize(gun->direction);
}

static void gun_update_reload(gun_t *gun)
{
    int time;

    if (!gun->reloading)
        return;
    time = sfClock_getElapsedTime(gun->clock).microseconds;
    if (time > gun->reload_time){
        sfClock_restart(gun->clock);
        gun->ammo = gun->max_ammo;
        gun->reloading = 0;
    }
}

static void gun_update_sprite(gun_t *gun)
{
    float angle;

    sfSprite_setPosition(gun->sprite, gun->pos);
    angle = vector_get_angle(gun->direction);
    sfSprite_setRotation(gun->sprite, angle);
    if (angle > 90 || angle < -90)
        sfSprite_setScale(gun->sprite, (sfVector2f){1, -1});
    else
        sfSprite_setScale(gun->sprite, (sfVector2f){1, 1});
}

void gun_update(gun_t *gun, sfVector2f player_pos,
    sfRenderWindow *window, sfView *view)
{
    player_pos.x += ((float)PLAYER_TOTAL_WIDTH / 2);
    player_pos.y += ((float)PLAYER_TOTAL_HEIGHT / 2);
    gun_update_direction(gun, player_pos, view, window);
    gun->pos = (sfVector2f){
        player_pos.x + gun->direction.x * 20,
        player_pos.y + gun->direction.y * 20};
    gun_update_reload(gun);
    gun_update_sprite(gun);
}

void gun_destroy(gun_t *gun)
{
    sfClock_destroy(gun->clock);
    free(gun);
}

void gun_shoot(gun_t *gun, game_t *game)
{
    bullet_t *bullet;
    int time = sfClock_getElapsedTime(gun->clock).microseconds;

    if (time < gun->fire_rate || gun->ammo <= 0)
        return;
    sfClock_restart(gun->clock);
    bullet = bullet_create(gun->pos, gun->direction,
        gun->bullet_speed, gun->damage);
    game->bullet_list = add_bullet_to_bullet_list(game->bullet_list, bullet);
    gun->ammo--;
}
