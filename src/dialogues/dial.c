/*
** EPITECH PROJECT, 2024
** main_game
** File description:
** dialogues
*/

#include "../../include/my_rpg.h"
#include "../../include/dial.h"

static conv_t *create_txt(char *character, char *content)
{
    conv_t *newTxT = malloc(sizeof(conv_t));

    newTxT->character = character;
    newTxT->content = content;
    newTxT->next = NULL;
    return newTxT;
}

static void add_txt(conv_t **dial_l, char *character, char *content)
{
    conv_t *newTxT = create_txt(character, content);
    conv_t *last = *dial_l;

    if (*dial_l == NULL) {
        *dial_l = newTxT;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = newTxT;
}

static conv_t *pars_txt(char *txt_buff)
{
    char **txt = my_str_in_array_txt(txt_buff);
    conv_t *dial = NULL;
    conv_t *curr;

    for (int i = 0; txt[i] != NULL; i += 2)
        add_txt(&dial, txt[i], txt[i + 1]);
    curr = dial;
    return dial;
}

conv_t *open_txt_file(char *path)
{
    int file = open(path, O_RDONLY);
    int len_v;
    struct stat len_s;
    char *buffer;
    conv_t *conv;

    stat(path, &len_s);
    len_v = len_s.st_size;
    buffer = malloc(sizeof(char) * (len_v + 1));
    read(file, buffer, len_v);
    buffer[len_v] = '\0';
    conv = pars_txt(buffer);
    close(file);
    return conv;
}

static void def_dial_box(game_t *game)
{
    game->ui->dial->dialBox = sfRectangleShape_create();
    sfRectangleShape_setSize(game->ui->dial->dialBox,
        (sfVector2f){sfView_getSize(game->cam->view).x, 150});
    sfRectangleShape_setFillColor(game->ui->dial->dialBox,
    sfColor_fromRGBA(0, 0, 0, 190));
}

sfText *set_sf_text(sfFont *font)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setFillColor(text, sfColor_fromRGB(255, 255, 255));
    return text;
}

void txt_update(sfEvent event, game_t *game)
{
    static int prev_space = 0;

    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        if (game->ui->dial->conv != NULL && prev_space == 0)
            game->ui->dial->conv = game->ui->dial->conv->next;
        prev_space = 1;
    } else
        prev_space = 0;
}

void set_text(game_t *game)
{
    game->ui = malloc(sizeof(ui_t));
    game->ui->dial = malloc(sizeof(dial_t));
    game->ui->dial->conv = open_txt_file("assets/txt/tuto.txt");
    game->ui->dial->font = sfFont_createFromFile("assets/fonts/Minecraft.ttf");
    def_dial_box(game);
    game->ui->dial->nameText = set_sf_text(game->ui->dial->font);
    sfText_setCharacterSize(game->ui->dial->nameText, 24);
    game->ui->dial->dialText = set_sf_text(game->ui->dial->font);
    sfText_setCharacterSize(game->ui->dial->dialText, 20);
    sfText_setString(game->ui->dial->nameText,
        game->ui->dial->conv->character);
    sfText_setString(game->ui->dial->dialText,
        game->ui->dial->conv->content);
    game->ui->dial->conv = game->ui->dial->conv->next;
    game->freeze_game = 0;
}

static void set_strings(game_t *game)
{
    sfText_setString(game->ui->dial->nameText,
        game->ui->dial->conv->character);
    sfText_setString(game->ui->dial->dialText,
        game->ui->dial->conv->content);
}

void txt_display(sfRenderWindow *window, game_t *game)
{
    int x = game->player->pos.x - sfView_getSize(game->cam->view).x / 2;
    int y = game->player->pos.y - sfView_getSize(game->cam->view).y / 2;

    game->freeze_game = 0;
    if (game->ui->dial->conv != NULL) {
        game->freeze_game = 1;
        set_strings(game);
        sfRectangleShape_setPosition(game->ui->dial->dialBox,
            (sfVector2f){x, game->player->pos.y + 100});
        sfRenderWindow_drawRectangleShape(
            window, game->ui->dial->dialBox, NULL);
        sfText_setPosition(game->ui->dial->nameText,
            (sfVector2f){x + 30, game->player->pos.y + 120});
        sfRenderWindow_drawText(
            window, game->ui->dial->nameText, NULL);
        sfText_setPosition(game->ui->dial->dialText,
            (sfVector2f){x + 40, game->player->pos.y + 150});
        sfRenderWindow_drawText(
            window, game->ui->dial->dialText, NULL);
    }
}
