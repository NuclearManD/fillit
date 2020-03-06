# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbrophy <dbrophy@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/05 15:02:31 by dbrophy           #+#    #+#              #
#    Updated: 2020/03/05 15:46:12 by dbrophy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror -Iinclude -Ilibft -c
NAME=fillit
SRC=	src/map_util.c \
	src/map_mem.c \


$(NAME): libft/libft.a
	$(CC) $(SRC) $(CFLAGS)
	$(CC) *.o -o $(NAME)
	
libft/libft.a:
	(cd libft; make)

all: $(NAME)

clean: 
	rm -rfv *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

