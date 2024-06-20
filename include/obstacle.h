/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** obstacle
*/

#ifndef OBSTACLE_H_
    #define OBSTACLE_H_

    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include "player.h"
    #include "mobs.h"

typedef struct obstacle_s {
    sfRectangleShape *sprite;
    sfVector2f pos;
    sfIntRect rect;
}obstacle_t;

obstacle_t *obstacle_create(sfVector2f pos);
void obstacle_display(obstacle_t *obstacle, sfRenderWindow *window);
void obstacle_destroy(obstacle_t *obstacle);

typedef struct obstacle_list_s {
    obstacle_t *obstacle;
    struct obstacle_list_s *next;
}obstacle_list_t;

obstacle_list_t *add_obstacle_to_obstacle_list(obstacle_list_t *list,
    obstacle_t *obstacle);
void obstacle_list_display(obstacle_list_t *list, sfRenderWindow *window);
void obstacle_list_destroy(obstacle_list_t *list);
void obstacle_list_remove(obstacle_list_t *list, obstacle_t *obstacle);

void add_door_coll(game_t *game);
void doors_update(game_t *game);

int check_collision_player_obstacle(player_t *player, obstacle_list_t *list);
int check_collision_mob_obstacle(mob_t *mob, obstacle_list_t *list);

#endif /* !OBSTACLE_H_ */
