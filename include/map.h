/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-florian.reynaud
** File description:
** my_hunter
*/

#ifndef MAP_H_
    #define MAP_H_

    #define CSV_N 9
    #define MAP_SIZE 200


    #include <SFML/Graphics/Types.h>

typedef struct game_s game_t;

typedef struct tile_list_s {
    sfSprite *tile;
    struct tile_list_s *next;
}tile_list_t;

typedef struct map_s {
    int **collisions;
    sfTexture *tileset;
    sfTexture *bg_txt;
    sfSprite *bg_spr;
    sfTexture *door_t;
    sfSprite **door_s;
    int *tab_doors;

    tile_list_t *lim;
    tile_list_t *calcu;
    tile_list_t *obj_c;
    tile_list_t *floor;
    tile_list_t *lab2;
    tile_list_t *lab;
    tile_list_t *doors;
    tile_list_t *c_doors;

}map_t;

int **def_csv_tab(char *buffer);
tile_list_t *def_csv_l(map_t *map, tile_list_t *calc, char *path);

int def_collide(game_t *game, map_t *map);

int **open_csv_coll(char *path);
map_t *gen_map(void);

void create_doors_s(game_t *game);
void update_doors_s(game_t *game);
void draw_doors_s(sfRenderWindow *window, game_t *game);
void destroy_doors_s(game_t *game);

void tiles_disp(sfRenderWindow *window, tile_list_t *map);
void obj_disp(sfRenderWindow *window, game_t *game, tile_list_t *current);
void parralax(sfRenderWindow *window, game_t *game);
void map_display(game_t *game, sfRenderWindow *window);
void map_destroy(game_t *game);

#endif /* !MAP_H_ */
