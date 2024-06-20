/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** save
*/

#include "../../include/my_rpg.h"

void load_save(game_t *game, char **tab)
{
    sfVector2f pos = {my_getnbr(tab[1]), my_getnbr(tab[2])};

    game->player->xp = my_getnbr(tab[0]);
    game->player->pos = pos;
    game->player->last_pos = pos;
    game->player->level = my_getnbr(tab[3]);
    game->player->keys = my_getnbr(tab[4]);
    game->player->pieces = my_getnbr(tab[5]);
    game->didacticiel = my_getnbr(tab[6]);
    if (game->didacticiel == 1) {
        sfMusic_stop(game->mus_tuto);
        sfMusic_play(game->mus_game);
        game->ui->dial->conv = NULL;
    }
}

void open_save(game_t *game)
{
    int file = open("src/player/.save", O_RDONLY);
    int len_v;
    struct stat len_s;
    char *buffer;
    char **tab;

    if (file < 0)
        return;
    stat("src/player/.save", &len_s);
    len_v = len_s.st_size;
    buffer = malloc(sizeof(char) * (len_v + 1));
    read(file, buffer, len_v);
    buffer[len_v] = '\0';
    tab = my_str_in_array_txt(buffer);
    load_save(game, tab);
    close(file);
    return;
}

void save_game(game_t *game)
{
    FILE *file = fopen("src/player/.save", "w");

    if (file == NULL) {
        my_putstr("Erreur lors de l'ouverture / création de la save.\n");
        return;
    }
    fprintf(file, "%d\n", game->player->xp);
    fprintf(file, "%d\n", (int)ceil(game->player->pos.x));
    fprintf(file, "%d\n", (int)ceil(game->player->pos.y));
    fprintf(file, "%d\n", game->player->level);
    fprintf(file, "%d\n", game->player->keys);
    fprintf(file, "%d\n", game->player->pieces);
    fprintf(file, "%d\n", game->didacticiel);
    fclose(file);
}
