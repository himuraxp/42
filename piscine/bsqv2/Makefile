# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/29 09:56:10 by ylarbi            #+#    #+#              #
#    Updated: 2015/07/30 22:50:14 by gmarguer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC = srcs/seek.c \
	  srcs/atoi.c \
	  srcs/ft_read.c \
	  srcs/handling.c \
	  srcs/ft_line.c \
	  srcs/ft_create.c \
	  srcs/ft_free.c \
	  srcs/main.c

OBJECT = seek.o \
		 atoi.o \
		 ft_read.o \
		 handling.o \
		 ft_line.o \
		 ft_create.o \
		 ft_free.o \
		 main.o

INC = ./includes/

all: $(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra -I $(INC) -c $(SRC)
	@gcc -Wall -Werror -Wextra -Ofast $(OBJECT) -o $(NAME)
	@echo "Loading..."
	@echo "$(NAME) created."

clean:
	@/bin/rm -f $(OBJECT)
	@echo ".o deleted."

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(NAME) deleted."

re: fclean all
