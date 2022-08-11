# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 03:27:34 by lrandria          #+#    #+#              #
#    Updated: 2022/08/10 23:54:59 by lrandria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
OBJS	=	$(SRCS:.c=.o)
SRCS	=	ft_bzero.c				\
			ft_memset.c				\
			ft_memcpy.c				\
			ft_memccpy.c			\
			ft_memcmp.c				\
			ft_memmove.c			\
			ft_memchr.c				\
			ft_strlen.c				\
			ft_isalpha.c			\
			ft_isdigit.c			\
			ft_isalnum.c			\
			ft_isascii.c			\
			ft_isprint.c			\
			ft_isset.c				\
			ft_toupper.c			\
			ft_tolower.c			\
			ft_strchr.c				\
			ft_strclen.c			\
			ft_strrchr.c			\
			ft_strcmp.c 			\
			ft_strncmp.c			\
			ft_strlcpy.c			\
			ft_strlcat.c			\
			ft_strnstr.c			\
			ft_atoi.c				\
			ft_calloc.c				\
			ft_strdup.c				\
			ft_strndup.c			\
			ft_substr.c				\
			ft_strjoin.c			\
			ft_strtrim.c			\
			ft_split.c				\
			ft_split_set.c			\
			ft_split_with_sep.c		\
			ft_itoa.c				\
			ft_strmapi.c			\
			ft_putchar_fd.c			\
			ft_putstr_fd.c			\
			ft_putendl_fd.c			\
			ft_putnbr_fd.c

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
