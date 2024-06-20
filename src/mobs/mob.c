/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** mobs
*/

#include "../../include/my_rpg.h"
#include <SFML/System/Clock.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include "../../include/utils.h"

static void mob_create_sprite(mob_t *mob)
{
    int h_ratio = MOB_TOTAL_HEIGHT / MOB_TEXTURE_HEIGHT;
    int w_ratio = MOB_TOTAL_WIDTH / MOB_TEXTURE_WIDTH;

    mob->sprite = sfSprite_create();
    mob->texture = sfTexture_createFromFile("assets/slime.png", NULL);
    sfSprite_setTexture(mob->sprite, mob->texture, sfFalse);
    mob->texture_rect = (sfIntRect){0, 0,
        MOB_TEXTURE_WIDTH, MOB_TEXTURE_HEIGHT};
    sfSprite_setTextureRect(mob->sprite, mob->texture_rect);
    sfSprite_setScale(mob->sprite, (sfVector2f){w_ratio, h_ratio});
    mob->hitbox = (sfIntRect){
        mob->pos.x + ((float)MOB_TOTAL_WIDTH / 4),
        mob->pos.y + ((float)MOB_TOTAL_HEIGHT / 4),
        MOB_TOTAL_WIDTH / 2, MOB_TOTAL_HEIGHT / 2};
}

mob_t *mob_create(sfVector2f pos, game_t *game)
{
    mob_t *mob = malloc(sizeof(mob_t));

    mob->pos = pos;
    mob->speed = 1;
    mob->alive = 1;
    mob->texture_clock = sfClock_create();
    mob->shoot_clock = sfClock_create();
    mob->last_pos = pos;
    mob->health = MOB_HP * LEVEL_RATIO(game->player->level);
    mob->health_max = MOB_HP * LEVEL_RATIO(game->player->level);
    mob_create_sprite(mob);
    mob->health_bar = health_bar_create((sfVector2f){mob->pos.x,
        mob->pos.y - 20}, (sfVector2f){MOB_TOTAL_WIDTH, 10}, mob->health,
        mob->health_max);
    return mob;
}

static void mob_update_texture(mob_t *mob)
{
    sfTime time = sfClock_getElapsedTime(mob->texture_clock);
    float seconds = sfTime_asSeconds(time);

    if (seconds > 0.1) {
        mob->texture_rect.left += MOB_TEXTURE_WIDTH;
        if (mob->texture_rect.left == MOB_TEXTURE_WIDTH * 6)
            mob->texture_rect.left = 0;
        if (mob->texture_rect.left >= MOB_TEXTURE_WIDTH * 9)
            mob->texture_rect.left = 0;
        sfSprite_setTextureRect(mob->sprite, mob->texture_rect);
        sfClock_restart(mob->texture_clock);
    }
}

static void mob_move(mob_t *mob, player_t *player)
{
    if (vector_get_distance(mob->pos, player->pos) < 200)
        return;
    mob->direction.x = player->pos.x - mob->pos.x;
    mob->direction.y = player->pos.y - mob->pos.y;
    mob->direction = vector_normalize(mob->direction);
    mob->pos.x += mob->direction.x * mob->speed;
    mob->pos.y += mob->direction.y * mob->speed;
}

static void mob_shoot(mob_t *mob, game_t *game)
{
    bullet_t *bullet;
    sfVector2f pos;
    sfVector2f player_pos;
    sfVector2f direction;

    if (sfClock_getElapsedTime(mob->shoot_clock).microseconds < 1000000)
        return;
    pos = (sfVector2f){
        mob->pos.x + ((float)MOB_TOTAL_WIDTH / 2),
        mob->pos.y + ((float)MOB_TOTAL_HEIGHT / 2)};
    player_pos = (sfVector2f){
        game->player->pos.x + ((float)PLAYER_TOTAL_WIDTH / 2),
        game->player->pos.y + ((float)PLAYER_TOTAL_HEIGHT / 2)};
    direction.x = player_pos.x - pos.x;
    direction.y = player_pos.y - pos.y;
    direction = vector_normalize(direction);
    bullet = bullet_create(pos, direction, 5, MOB_DAMAGE);
    set_bullet_type(bullet, MOB_BULLET);
    game->bullet_list = add_bullet_to_bullet_list(game->bullet_list, bullet);
    sfClock_restart(mob->shoot_clock);
}

void mob_set_position(mob_t *mob, sfVector2f pos)
{
    mob->pos = pos;
    sfSprite_setPosition(mob->sprite, mob->pos);
    mob->hitbox = (sfIntRect){
        mob->pos.x + ((float)MOB_TOTAL_WIDTH / 4),
        mob->pos.y + ((float)MOB_TOTAL_HEIGHT / 4),
        MOB_TOTAL_WIDTH / 2, MOB_TOTAL_HEIGHT / 2};
    health_bar_update(mob->health_bar, (sfVector2f){mob->pos.x,
        mob->pos.y - 20}, mob->health, mob->health_max);
}

void mob_update(mob_t *mob, sfRenderWindow *window, game_t *game)
{
    sfTime time = sfClock_getElapsedTime(mob->texture_clock);
    float seconds = sfTime_asSeconds(time);

    if (vector_get_distance(mob->pos, game->player->pos) > 1000)
        return;
    mob->last_pos = mob->pos;
    mob_move(mob, game->player);
    mob_shoot(mob, game);
    mob_update_texture(mob);
    mob_set_position(mob, mob->pos);
    check_collision_mob_obstacle(mob, game->obstacle_list);
    if (mob->health <= 0)
        mob->alive = 0;
}

void mob_display(mob_t *mob, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, mob->sprite, NULL);
    health_bar_display(mob->health_bar, window);
}

void mob_destroy(mob_t *mob)
{
    sfSprite_destroy(mob->sprite);
    sfTexture_destroy(mob->texture);
    sfClock_destroy(mob->texture_clock);
    health_bar_destroy(mob->health_bar);
    free(mob);
}
