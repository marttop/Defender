##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

NAME	=	my_defender

CC	=	gcc

SRC	=	src/start.c \
		src/event_controll.c \
		src/turret_shooting.c \
		src/wave_button.c \
		src/wave2.c \
		src/turret_rotate.c \
		src/slider.c \
		src/slider_arrow.c \
		src/message.c \
		src/targetting2.c \
		src/display.c \
		src/game_loop.c \
		src/pause.c \
		src/menu.c \
		src/menu2.c \
		src/round_mob.c \
		src/clock.c \
		src/init_all.c \
		src/destroy.c \
		src/destroy_sounds.c \
		src/move.c \
		src/targetting.c \
		src/turret_support.c \
		src/selected_turret.c \
		src/selected2.c \
		src/turret_select.c \
		src/button_init.c \
		src/pathfinding.c \
		src/turret.c \
		src/selected.c \
		src/side_menu.c \
		src/mobs.c \
		src/turret_area.c \
		src/destroy2.c \
		src/wave.c \
		utils/my_strlen.c \
		utils/my_strdup.c \
		utils/list_utils_buttons.c \
		utils/get_next_line.c \
		utils/list_utils_buttons2.c \
		utils/get_file.c \
		utils/randomize.c \
		utils/get_int.c \
		utils/parse_map.c \
		utils/list_utils_targetting.c \
		utils/wave_parsor.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra
CFLAGS	+=	-I./include -g3
FFLAGS	+=	-l csfml-system
FFLAGS	+=	-l csfml-graphics
FFLAGS	+=	-l csfml-audio
FFLAGS	+=	-l csfml-window
FFLAGS  +=	-lm

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(FFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
