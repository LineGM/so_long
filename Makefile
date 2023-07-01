# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhanna <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 17:33:38 by lhanna            #+#    #+#              #
#    Updated: 2022/06/16 17:33:40 by lhanna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CFLAGS	= -Wall -Wextra -Werror
CC		= gcc

MLX_PATH	= ./minilibx
HEADER		= so_long.h
RM			= rm -f

SRCS		= main.c		image.c		map.c	  \
			mem.c			enemy.c 	keypress.c\
			move.c			itoa.c 		flags.c   \
			get_next_line/get_next_line.c		  \
			get_next_line/get_next_line_utils.c		\

OBJS 		= ${SRCS:.c=.o}

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS}  -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS) $(HEADER)
			$(MAKE) --directory=minilibx
			$(CC) $(OBJS) $(CFLAGS) -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus:		all

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}
			make -C $(MLX_PATH) clean

mlx_re:
			make -C $(MLX_PATH) re

re: 		fclean all

.PHONY:		all clean fclean re bonus
