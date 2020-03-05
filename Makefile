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
CFLAGS=-Wall -Wextra -Werror -I. -Ilibft -c
NAME=fillit
SRC=	map_intersect.c \


$(NAME):
	mkdir -f build
	$(CC) $(SRC) $(CFLAGS)
	$(CC) build/*.o -o $(NAME)
	
libft/libft.a:
	cd libft
	make
	cd ..

all: $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

