# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/18 13:43:08 by jfritz            #+#    #+#              #
#    Updated: 2021/07/19 11:33:51 by jfritz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = so_long.a

LIBFTNAME = libft.a

CFLAGS = -Werror -Wall -Wextra

OBJS := $(*.o)

SRC = main.c

MAPTOOLS = ./map/ft_get_map.c

LIBFTPATH = ./libft/

all: $(NAME)

${NAME}:
	make -C ${LIBFTPATH}
	mv $(LIBFTPATH)${LIBFTNAME} ${LIBFTNAME}
	${CC} ${CFLAGS} ${SRC} $(MAPTOOLS) ${LIBFTNAME} -o ${NAME}

clean:
		rm -rf *.o

fclean: clean
	rm -f $(LIBFTNAME) ${OBJS} $(NAME)

re: fclean ${NAME}