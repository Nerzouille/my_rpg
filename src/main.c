/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myhunter-florian.reynaud
** File description:
** main
*/
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/Window.h>
#include "../include/my_rpg.h"
#include "../include/my.h"

static void put_description(void)
{
    char *help = "SPACE BREAKOUT\n\n"
    "\tOur my_rpg Project,\n\t Welcome in a spaceshipe where nothing makes "
    "sense.\n\t Be prepared to face the unexpected.\n\n"
    "COMMANDS\n"
    "\t-Left click / Space = SHOOT\n"
    "\t-R = Move RELOAD\n"
    "\t-Space = SKIP DIALOG\n"
    "\t-Z = Move FORWARD\n"
    "\t-Q = Move LEFT\n"
    "\t-S = Move BACKWARD\n"
    "\t-D = Move RIGHT\n"
    "\t-E = Open INVENTORY\n"
    "\t-Escape = Leave MENU\n\n"
    "THIS GAME USES AUTO SAVE\n";

    printf("%s", help);
}

int do_app(void)
{
    app_t *app = app_create();

    app_loop(app);
    app_destroy(app);
    return 0;
}

int main(int ac, char **av)
{
    int return_code = 0;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0){
        put_description();
    } else {
        return_code = do_app();
    }
    return return_code;
}
