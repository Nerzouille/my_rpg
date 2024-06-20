##
## EPITECH PROJECT, 2023
## B-MUL-100-LYN-1-1-myhunter-florian.reynaud
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/app.c	\
		src/game.c	\
		src/game_destroy.c	\
		src/game_health_bar.c	\
		src/game_xp_bar.c	\
		src/player/player.c	\
		src/player/update.c	\
		src/player/input.c	\
		src/player/shoot.c	\
		src/player/save.c	\
		src/utils.c	\
		src/camera.c	\
		src/bullet/bullets.c	\
		src/bullet/bullet_list.c	\
		src/bullet/collision.c	\
		src/map/tiling.c	\
		src/map/maping.c	\
		src/map/def_collisions.c	\
		src/map/map.c	\
		src/map/doors.c	\
		src/gun/gun.c	\
		src/gun/blueprint.c	\
		src/obstacle/obstacle.c	\
		src/obstacle/obstacle_list.c	\
		src/obstacle/doors_coll.c	\
		src/obstacle/collision.c	\
		src/event/buttons.c	\
		src/event/resolution.c	\
		src/menu/menu.c	\
		src/menu/settings.c	\
		src/inventory/create.c	\
		src/inventory/handle_event.c	\
		src/inventory/render_inventory.c	\
		src/inventory/special_slots.c	\
		src/inventory/render_weapon.c	\
		src/inventory/get_weapon.c	\
		src/inventory/render_sniper.c	\
		src/inventory/render_smg.c	\
		src/inventory/render_assault.c	\
		src/inventory/render_pistol.c	\
		src/inventory/click_close_inv.c	\
		src/dialogues/dial.c	\
		src/dialogues/main_dials.c	\
		src/dialogues/dial_utils.c	\
		src/dialogues/d_spwan_point.c	\
		src/mobs/mob.c	\
		src/mobs/mob_list.c	\
		src/mobs/spawner.c	\
		src/mobs/spwan_point.c	\
		src/health_bar.c \
		src/xp_bar.c \
		src/songs.c \
		src/event/buttons_on_view.c	\
		src/pause/pause.c	\


NAME = my_rpg

LIB_SRC	= 	$(wildcard	lib/my/*.c)

LIB_OBJ	=	$(LIB_SRC:.c=.o)

LIB_NAME	=	libmy.a

LIB_FLAG	=	-L./ -lmy

CSFML_FLAG	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

MATH_FLAG	=	-lm

all:	make_lib	compile

make_lib:	$(LIB_OBJ)
	ar	rc	$(LIB_NAME)	lib/my/*.o

compile:
	gcc -g3 -o $(NAME) $(SRC) $(LIB_FLAG) $(CSFML_FLAG) $(MATH_FLAG)

clean:
	rm -f $(LIB_OBJ)

fclean: clean
	rm -f $(LIB_NAME) $(NAME)

re:	fclean	all
