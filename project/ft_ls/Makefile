# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 14:26:00 by ylarbi            #+#    #+#              #
#*   Updated: 2016/01/21 19:07:01 by ylarbi           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME	=	libft/libft.a
SRCNAME	= 	init.c 			print.c 		print_file.c 	filter.c	 \
			parse.c 		ft_ls.c 		error.c			tools.c		 \
			more_list.c		list.c			dir.c			file.c		 \
			data_lst.c 		sort.c			more_print.c 	moar_list.c	 \
			multi_arg.c		permissions.c	recursif.c		columns.c	 \
		  	more_sort.c		more_print_file.c				color.c
SRCPATH =	src/
SRC		=	$(addprefix $(SRCPATH)/,$(SRCNAME))
FLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-Iinc
LIB		=	-Llibft/ -lft
EXE		=	ft_ls
LIBFT	=	-Clibft/

all: $(NAME)

$(NAME): logo
		@make $(LIBFT)
		@gcc $(FLAGS) $(INCLUDE) $(LIB) -o $(EXE) $(SRC)
		@echo "\033[32m------------>          Program compilation\033[0m"

logo:
		@echo "\033[2J"
		@echo "\033[200A"
		@echo "\033[31m               :::        ::::::::        \033[0m"
		@echo "\033[31m              :+:       :+:    :+:        \033[0m"
		@echo "\033[32m             +:+       +:+                \033[0m"
		@echo "\033[32m            +#+       +#++:++#++          \033[0m"
		@echo "\033[33m           +#+              +#+           \033[0m"
		@echo "\033[33m          #+#       #+#    #+#            \033[0m"
		@echo "\033[36m         ########## ########        ylarbi\033[0m"
		@echo "\n"
		@echo "                                     ft_ls"

clean: logo
		@echo "\033[31m------------>               Suppression .o\033[0m"
		@rm -rf $(OBJPATH)
fclean: clean
		@echo "\033[31m------------>          Suppression program\033[0m"
		@rm -rf $(NAME) $(EXE)
re: fclean all

.PHONY: clean fclean re all logo
