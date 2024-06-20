/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-charly.palliere
** File description:
** menu
*/

#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/Event.h>
#include <SFML/Audio.h>

#ifndef MENU_H_
    #define MENU_H_

typedef struct app_s app_t;

enum button_state {
    NONE = 0,
    HOVER,
    PRESSED
};

typedef struct button_s {
    sfRectangleShape *rect;
    sfIntRect anim;
    sfVector2f pos;
    sfVector2f scale;
    sfTexture *txt;
    sfSprite *sprt;
    sfVector2f org_pos;
    enum button_state state;
}button_t;

typedef struct menu_s {
    int load;
    sfTexture *bg_txt;
    sfSprite *bg_sprt;
    sfTexture *load_txt;
    sfSprite *load_sprt;
    button_t *start;
    button_t *opts;
    button_t *back;
    button_t *full;
    button_t *maxRes;
    button_t *minRes;
    button_t *quit;
    app_t *app;
    sfSoundBuffer* buffer_button;
    sfSound* sound_button;
}menu_t;

typedef struct settings_s {
    sfRenderWindow *window;
    sfVector2u org_size;
    sfVideoMode size;
    sfBool isFull;
    int sound;
    int music;
}settings_t;


void menu_display(menu_t *menu, settings_t *settings);
menu_t *menu_create(app_t *app);
settings_t *init_settings(menu_t *menu);

void init_button(menu_t *menu);
void button_event(button_t *button, sfEvent *event, menu_t *menu);

void check_click(menu_t *menu, settings_t *settings, sfEvent event);
void check_resolution(menu_t *menu, settings_t *settings, sfEvent *event);
void resize_item(sfRenderWindow *window, sfSprite *sprite,
    sfVector2u orgWin, sfVector2f orgBut);
sfBool is_hover(sfEvent *event, button_t *button);
sfBool on_click(sfEvent *event, button_t *button);
void menu_loop(menu_t *menu, sfEvent event, settings_t *settings);
void settings_loop(settings_t *settings, sfEvent event, menu_t *menu);

void menu_destroy(menu_t *menu);


#endif /* !MENU_H_ */
