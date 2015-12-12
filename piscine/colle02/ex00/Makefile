#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chdenis <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/25 16:16:53 by chdenis           #+#    #+#              #
#    Updated: 2015/07/25 20:13:28 by chdenis          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = colle-2

SRC = srcs/main.c srcs/parse.c srcs/fts.c srcs/check.c 

OBJECT = main.o parse.o fts.o check.o

all: $(NAME)

$(NAME):
	gcc -Werror -Wextra -Wall -I./includes -c $(SRC)
	gcc -Werror -Wextra -Wall -o $(NAME) $(OBJECT)

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all