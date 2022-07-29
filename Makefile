# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 23:24:55 by lrandria          #+#    #+#              #
#    Updated: 2022/07/29 18:08:20 by lrandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	cub3D
MLX			=	minilibx-linux/libmlx.a
LFT			= 	libft/libft.a
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -g3
INC			=	-I ./
LIBS		=	-L ./libft -lft -L ./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd
OBJS		= 	$(SRCS:.c=.o)
HDR			=	./inc/cub3D.h
SRCS 		=	./srcs/keying.c \
				./srcs/raycasting_tools.c \
				./srcs/raycasting.c \
				./srcs/coloring.c \
				./srcs/init_parsing.c \
				./srcs/cub3d.c \
				./srcs/parsing_one.c \
				./srcs/parsing_two.c \
				./srcs/get_next_line.c \
				./srcs/get_next_line_utils.c\
				./srcs/tools.c \
				./srcs/exiting.c \
				./srcs/init_raycasting.c \
				./srcs/updating_raycasting.c \
				./srcs/texturing.c \
				./srcs/moving.c

all:			$(MLX) $(LFT) $(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

$(MLX):
			make -C ./minilibx-linux
$(LFT):
			make -C ./libft

%.o:		%.c $(HDR)
			$(CC) $(CFLAGS) $(INC) -c -o $@ $< 

clean:
			rm -rf $(OBJS)
			make -C ./libft clean

fclean:		clean
			rm -rf $(NAME)
			make -C ./libft fclean

re:			fclean all

.PHONY:		all clean fclean re bonus
