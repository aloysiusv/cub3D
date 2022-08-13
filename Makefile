# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 21:00:01 by lrandria          #+#    #+#              #
#    Updated: 2022/08/14 00:02:17 by nsartral         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d
MLX			=	minilibx-linux/libmlx.a
LFT			= 	libft/libft.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g3 -MMD -MP
LIBS		=	-L ./libft -lft -L ./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd
INC			=	inc/cub3d.h 						\
				inc/error_msgs.h 					\

SRCS		=	0_main.c 							\
				1_parsing_get_file.c 				\
				2_parsing_check_info.c 				\
				3_parsing_get_paths.c 				\
				4_parsing_get_colours.c				\
				5_parsing_get_map.c					\
				6_parsing_check_map.c 				\
				7_parsing_check_walls.c 			\
				7_parsing_check_walls_bis.c			\
				8_launch_game.c 					\
				9_exec_init_moves.c 				\
				10_exec_init_pov.c 					\
				11_exec_init_screen.c 				\
				12_exec_init_textures.c 			\
				13_exec_init_images.c 				\
				14_exec_hook_keying.c 				\
				14_exec_hook_releasing.c 			\
				15_exec_raycast_raycasting.c 		\
				15_exec_raycast_init_ray.c 			\
				15_exec_raycast_processing_ray.c 	\
				15_exec_raycast_texturing_scene.c 	\
				15_exec_raycast_moving.c 			\
				utils_free.c 						\
				utils_str.c 						\
				utils_tab.c 						\
				utils_whitespaces.c					\

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
