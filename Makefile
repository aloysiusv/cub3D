SRCS 			=	./srcs/keying.c \
					./srcs/raycasting_tools.c \
					./srcs/raycasting.c \
					./srcs/coloring.c \
					./srcs/initing_parsing.c \
					./srcs/cub3d.c \
					./srcs/parsing_one.c \
					./srcs/parsing_two.c \
					./srcs/get_next_line.c \
					./srcs/get_next_line_utils.c\
					./srcs/tools.c \
					./srcs/exiting.c \
					./srcs/initing_raycasting.c \
					./srcs/updating_raycasting.c \
					./srcs/texturing.c \
					./srcs/moving.c

OBJS			= 	$(SRCS:.c=.o)

LIBS			= 	-L ./minilibx-linux -lmlx -lXext -lX11 -lm

CC				= 	gcc

RM				= 	rm -f

CFLAGS			= 	-Wall -Wextra -Werror -g3 -I./srcs -I./minilibx-linux

NAME 			=	cub3D

all:			$(NAME)

$(NAME):		$(OBJS)
				gcc $(CFLAGS) -g3 -o $(NAME) $(OBJS) $(LIBS)
				$(RM) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME) $(OBJS)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
