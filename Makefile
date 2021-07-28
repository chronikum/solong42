# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/18 13:43:08 by jfritz            #+#    #+#              #
#    Updated: 2021/07/28 09:01:36 by jfritz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = so_long.a

LIBFTNAME = libft.a

CFLAGS = -Werror -Wall -Wextra

MINILIBX = -I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit

OBJS := $(*.o)

SRC = main.c

MAPTOOLS = ./map/ft_get_map.c ./map/ft_check_map_file.c ./map/ft_map_validation_helpers.c \
./map/ft_aux_check_map_file.c

RENDERSRC = ./render/setup_hooks.c ./render/ft_control_player.c ./render/ft_keycode_action.c ./render/ft_render_basic.c \
./render/ft_aux_window.c ./render/ft_aux_logic.c ./render/ft_put_img.c ./render/ft_images.c ./render/ft_character.c \
./render/ft_trees.c ./render/ft_aux_render.c ./render/ft_game_over.c

ANIMATESRC = ./animation/ft_animate.c

RANDOMSRC = ./random/ft_seed.c

ENEMYSRC = ./enemies/ft_img_enemy.c ./enemies/ft_put_enemy.c ./enemies/ft_move_enemy.c

BONUSSRC = ./bonus/ft_if_putenemy.c

LIBFTPATH = ./libft/

all: $(NAME)

${NAME}: fclean
	make -C ${LIBFTPATH}
	mv $(LIBFTPATH)${LIBFTNAME} ${LIBFTNAME}
	${CC} ${CFLAGS} ${SRC} $(MAPTOOLS) ${RENDERSRC} ${RANDOMSRC} ${ENEMYSRC} ${BONUSSRC} ${ANIMATESRC} ${LIBFTNAME} ${MINILIBX} -o ${NAME} -D BONUS=0

clean:
	rm -rf *.o

bonus: fclean
	make -C ${LIBFTPATH}
	mv $(LIBFTPATH)${LIBFTNAME} ${LIBFTNAME}
	${CC} ${CFLAGS} ${SRC} $(MAPTOOLS) ${RENDERSRC} ${RANDOMSRC} ${ENEMYSRC} ${BONUSSRC} ${ANIMATESRC} ${LIBFTNAME} ${MINILIBX} -o ${NAME} -D BONUS=1

fclean: clean
	rm -f $(LIBFTNAME) ${OBJS} $(NAME)

re: fclean ${NAME}