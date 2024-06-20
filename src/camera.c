/*
** EPITECH PROJECT, 2024
** main_game
** File description:
** camera
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>
#include "../include/camera.h"
#include <stdlib.h>

cam_t *camera_create(sfRenderWindow *window, float zoom)
{
    cam_t *camera = malloc(sizeof(cam_t));
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfVector2f center;
    sfVector2f size;

    camera->view = sfView_create();
    center.x = (float)window_size.x / 2;
    center.y = (float)window_size.y / 2;
    sfView_setCenter(camera->view, center);
    size.x = window_size.x / zoom;
    size.y = window_size.y / zoom;
    sfView_setSize(camera->view, size);
    camera->zoom = zoom;
    return camera;
}

void camera_update(cam_t *cam, sfVector2f center, sfRenderWindow *window)
{
    sfVector2f size;

    size.x = sfRenderWindow_getSize(window).x / cam->zoom;
    size.y = sfRenderWindow_getSize(window).y / cam->zoom;
    sfView_setCenter(cam->view, center);
    sfView_setSize(cam->view, size);
}

void camera_destroy(cam_t *cam)
{
    sfView_destroy(cam->view);
    free(cam);
}
