/*
** EPITECH PROJECT, 2024
** main_game
** File description:
** tiling
*/

#include "../../include/my_rpg.h"
#include "../../include/map.h"

void gen_calc(map_t *map)
{
    char *asset = "assets/sky_bg.jpg";

    map->bg_txt = sfTexture_createFromFile("assets/sky_bg.jpg", NULL);
    map->bg_spr = sfSprite_create();
    sfSprite_setTexture(map->bg_spr, map->bg_txt, sfTrue);
    map->lim = def_csv_l(map, map->lim,
        "assets/csv/map_space_breakout_lim.csv");
    map->calcu = def_csv_l(map, map->calcu,
        "assets/csv/map_space_breakout_Tuiles.csv");
    map->floor = def_csv_l(map, map->calcu,
        "assets/csv/map_space_breakout_on_floor.csv");
    map->obj_c = def_csv_l(map, map->obj_c,
        "assets/csv/map_space_breakout_obj.csv");
    map->lab2 = def_csv_l(map, map->lab2,
        "assets/csv/map_space_breakout_laby2.csv");
    map->lab = def_csv_l(map, map->lab,
        "assets/csv/map_space_breakout_laby.csv");
    map->doors = def_csv_l(map, map->doors,
        "assets/csv/map_space_breakout_haut_p.csv");
}

void def_coll(map_t *map)
{
    map->collisions = open_csv_coll("assets/csv/map_space_breakout_coll.csv");
}

map_t *gen_map(void)
{
    map_t *map = malloc(sizeof(map_t));
    int tileCount = 0;
    char *asset = "assets/assets_space_map.png";

    map->tileset = sfTexture_createFromFile(asset, NULL);
    def_coll(map);
    gen_calc(map);
    return map;
}
