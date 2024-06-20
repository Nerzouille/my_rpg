/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** spawner
*/

#include "../../include/my_rpg.h"
#include <SFML/Config.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Types.h>
#include <SFML/System/Vector2.h>
#include "../../include/utils.h"

mob_spawner_t *spawner_create(sfVector2f pos, int spawn_rate, sfVector2f size)
{
    mob_spawner_t *spawner = malloc(sizeof(mob_spawner_t));

    spawner->pos = pos;
    spawner->spawn_rate = spawn_rate;
    spawner->can_spawn = sfTrue;
    spawner->clock = sfClock_create();
    spawner->mob_count = 0;
    spawner->mob_positions = NULL;
    spawner->hitbox = (sfIntRect){pos.x, pos.y, size.x, size.y};
    return spawner;
}

void spawner_set_mob_positions(mob_spawner_t *spawner, sfVector2f *positions,
    int nb_mob)
{
    spawner->mob_positions = malloc(sizeof(sfVector2f) * nb_mob);
    for (int i = 0; i < nb_mob; i++)
        spawner->mob_positions[i] = positions[i];
    spawner->mob_count = nb_mob;
}

void spawner_displaye(sfRenderWindow *window, mob_spawner_t *spawner)
{
    display_hitbox(spawner->hitbox, window);
}

static void spawner_update_can_spawn(mob_spawner_t *spawner)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(spawner->clock)) >
        spawner->spawn_rate && !spawner->can_spawn)
        spawner->can_spawn = sfTrue;
}

void spawner_update(mob_spawner_t *spawner, game_t *game)
{
    mob_t *mob;

    if (game->didacticiel == 1 && spawner->can_spawn
        && check_collision(game->player->hitbox,
            spawner->hitbox) && game->freeze_game == 0) {
        for (int i = 0; i < spawner->mob_count; i++) {
            mob = mob_create(spawner->mob_positions[i], game);
            game->mob_list = add_mob_to_mob_list(game->mob_list, mob);
        }
        spawner->can_spawn = sfFalse;
        sfClock_restart(spawner->clock);
    }
    spawner_update_can_spawn(spawner);
}

void spawner_destroy(mob_spawner_t *spawner)
{
    sfClock_destroy(spawner->clock);
    if (spawner->mob_positions != NULL)
        free(spawner->mob_positions);
    free(spawner);
}
