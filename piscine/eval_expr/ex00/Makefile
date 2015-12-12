# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylarbi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/24 22:39:11 by ylarbi            #+#    #+#              #
#    Updated: 2015/07/26 11:22:08 by ylarbi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr

FLAG = -Wall -Werror -Wextra

SRC = srcs/main.c \
	  srcs/eval_expr.c \
	  srcs/suppr_spaces.c \
	  srcs/ft_parse_nbr.c \
	  srcs/do_op.c \
	  srcs/ft_putchar.c \
	  srcs/ft_putnbr.c \
	  srcs/ft_strlen.c

SRO = main.o \
	  eval_expr.o \
	  suppr_spaces.o \
	  ft_parse_nbr.o \
	  do_op.o \
	  ft_putchar.o \
	  ft_putnbr.o \
	  ft_strlen.o

INC = ./includes/

all: $(NAME)

$(NAME):
		gcc $(FLAG) -I$(INC) -c $(SRC)
		gcc $(FLAG) $(SRO) -o $(NAME)

clean:
		/bin/rm -f  $(SRO)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
