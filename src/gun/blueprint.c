/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** blueprint
*/


#include "../../include/my_rpg.h"
#include "../../include/my.h"
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Types.h>
#include <SFML/System/Vector2.h>
#include "../../include/utils.h"

gun_blueprint_t gun_table[] = {
    {"pistol", 10, 12, 500000, 1000000, 10, "assets/pistol.png"},
    {"assault", 5, 30, 200000, 2000000, 15, "assets/ar.png"},
    {"sniper", 100, 5, 2000000, 2000000, 20, "assets/sniper.png"},
    {"smg", 5, 15, 100000, 1000000, 10, "assets/smg.png"},
};

const int gun_table_size = sizeof(gun_table) / sizeof(gun_blueprint_t);

gun_blueprint_t *get_gun_blueprint(char *name)
{
    for (int i = 0; i < gun_table_size; i++) {
        if (my_strcmp(gun_table[i].name, name) == 0)
            return &gun_table[i];
    }
    return NULL;
}
