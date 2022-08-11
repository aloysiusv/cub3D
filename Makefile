# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 21:00:01 by lrandria          #+#    #+#              #
#    Updated: 2022/08/11 15:53:59 by lrandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d
MLX			=	minilibx-linux/libmlx.a
LFT			= 	libft/libft.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g3 -MMD -MP
LIBS		=	-L ./libft -lft -L ./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd
INC			=	inc/cub3d.h 					\
				inc/error_msgs.h 				\

SRCS		=	main.c 							\
				exec_hook_exiting.c 			\
				exec_hook_keying.c 				\
				exec_hook_releasing.c 			\
				exec_init_moves.c 				\
				exec_init_pov.c 				\
				exec_init_screen.c 				\
				exec_init_images.c 				\
				exec_init_textures.c 			\
				exec_raycast_raycasting.c 		\
				exec_raycast_init_ray.c 		\
				exec_raycast_processing_ray.c 	\
				exec_raycast_texturing_scene.c 	\
				exec_raycast_moving.c 			\
				parsing_coloring.c 				\
				parsing_two.c 					\
				parsing_one.c 					\
				parsing_custom_gnlz_utils.c		\
				parsing_custom_gnlz.c 			\
				parsing_init_parsing.c 			\
				parsing_check_file.c 			\
				parsing_check_info.c 			\
				parsing_check_map.c 			\
				parsing_get_paths.c 			\
				parsing_get_colours.c			\
				parsing_get_map.c				\
				utils_free.c 					\
				utils_str.c 					\
				utils_tab.c 					\
				utils_parsing.c 				\
				printing.c		 				\

OBJS		:=	$(addprefix ./objs/,$(SRCS:%.c=%.o))
DEP			=	$(addprefix ./objs/,$(OBJS:%.o=%.d))

all:			$(MLX) $(LFT) $(NAME)

-include $(DEP)

./objs/%.o: 	./srcs/%.c
				@mkdir -p $(@D)
				$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):		$(OBJS) $(INC)
				$(CC) $(CFLAGS) -I incl -o $(NAME) $(OBJS) $(LIBS)

$(MLX):
				make -C ./minilibx-linux
$(LFT):
				make -C ./libft

clean:
				rm -rf objs/
				make -C ./libft clean

fclean:			clean
				rm -rf $(NAME)
				make -C ./libft fclean

re:				fclean all

.PHONY:			all clean fclean re
