# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 21:00:01 by lrandria          #+#    #+#              #
#    Updated: 2022/08/09 11:25:08 by lrandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d
MLX			=	minilibx-linux/libmlx.a
LFT			= 	libft/libft.a
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -g3
INC			=	-I ./
LIBS		=	-L ./libft -lft -L ./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd
OBJS		=	$(SRCS:.c=.o)
HDR			=	./inc/cub3d.h
SRCS		=	./cub3d.c 								\
				./exec/hooking/exiting.c 				\
				./exec/hooking/keying.c 				\
				./exec/hooking/releasing.c 				\
				./exec/init/moves.c 					\
				./exec/init/pov.c 						\
				./exec/init/screen.c 					\
				./exec/init/images.c 					\
				./exec/init/textures.c 					\
				./exec/raycasting/raycasting.c 			\
				./exec/raycasting/init_ray.c 			\
				./exec/raycasting/processing_ray.c 		\
				./exec/raycasting/texturing_scene.c 	\
				./exec/raycasting/moving.c 				\
				./parsing/coloring.c 					\
				./parsing/utils_parsing.c 				\
				./parsing/parsing_two.c 				\
				./parsing/parsing_one.c 				\
				./parsing/custom_gnlz_utils.c			\
				./parsing/custom_gnlz.c 				\
				./parsing/init_parsing.c 				\
				./parsing/printing.c 					\
				./parsing/check_file.c 					\
				./utils/utils_free.c 					\
				./utils/utils_str.c 					\
				./utils/utils_tab.c 					\
				./utils/utils_nodes.c

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

.PHONY:		all bonus clean fclean re
