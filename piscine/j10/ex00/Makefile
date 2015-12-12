# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/21 10:11:48 by ylarbi            #+#    #+#              #
#    Updated: 2015/07/21 16:45:44 by ylarbi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = srcs/ft_putchar.c \
	  srcs/ft_putstr.c \
	  srcs/ft_strcmp.c \
	  srcs/ft_strlen.c \
	  srcs/ft_swap.c

LIB = srcs/ft_putchar.o \
	  srcs/ft_putstr.o \
	  srcs/ft_strcmp.o \
	  srcs/ft_strlen.o \
	  srcs/ft_swap.o

INCLUDE = includes/

all: $(NAME)

$(NAME):
	gcc -i $(INCLUDE) -c $(SRC) && ar rc $(NAME) $(LIB) && ranlib $(NAME)

clean:
	/bin/rm -f $(LIB)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
