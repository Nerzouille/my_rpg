/*
** EPITECH PROJECT, 2024
** main_game
** File description:
** camera
*/

#ifndef CAMERA_H_
    #define CAMERA_H_

    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>

typedef struct cam_s {
    sfView *view;
    float zoom;
}cam_t;

cam_t *camera_create(sfRenderWindow *window, float zoom);
void camera_update(cam_t *cam, sfVector2f center, sfRenderWindow *window);
void camera_destroy(cam_t *cam);

#endif /* !CAMERA_H_ */
