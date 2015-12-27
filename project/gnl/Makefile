# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 14:26:00 by ylarbi            #+#    #+#              #
<<<<<<< HEAD
#*   Updated: 2015/12/22 16:05:48 by ylarbi           ###   ########.fr       *#
=======
#*   Updated: 2015/12/24 13:10:20 by ylarbi           ###   ########.fr       *#
>>>>>>> 4f42a4fe446ce3cdedb9b97a5e28297c741c7aaf
#                                                                              #
# **************************************************************************** #

NAME = ./libft/libft.a
SRC  = ./libft/*.c
GSRC  = *.c
LOBJ  = *.o
FLAGS =  -Wall -Wextra -Werror
INCLUDE = ./libft/libft.h
GNL = gnl

all: $(NAME)

$(NAME): logo
		@gcc $(FLAGS) -I$(INCLUDE) -c $(SRC) $(GSRC)
		@gcc $(FLAGS) -o $(GNL) $(LOBJ)
		@echo "\033[32m------------>\033[0m        Compilation programme"
		@ar rc $(NAME) $(LOBJ)
		@echo "\033[36m------------>\033[0m           Creation librairie"
		@ranlib $(NAME)
		@echo "\033[36m------------>\033[0m     Creation index librairie"
logo:
		@echo "\033[31m              ___   _  _   _               \033[0m"
		@echo "\033[31m __         /  __| | \| | | |           __ \033[0m"
		@echo "\033[32m|**|       | /  _  |    | | |          |**|\033[0m"
		@echo "\033[33m|__|       | \ | | |    | | |__        |__|\033[0m"
		@echo "\033[36m ********** \____| |_|\_| |____|********** \033[0m"
		@echo "\n"
mouli1: logo
		@-C libft/ fclean && make -C libft/
		@echo "\033[32m------------>\033[0m          Compilation mouli 1"
mouli2: logo
		@clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c
		get_next_line.c
		@echo "\033[32m------------>\033[0m        Compilation mouli 2.1"
		@clang  -Wall -Wextra -Werror -I libft/includes -o main.o -c main.o
		@echo "\033[32m------------>\033[0m        Compilation mouli 2.2"
		@clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/
		-lft
		@echo "\033[32m------------>\033[0m  Compilation mouli 2.3 Final"
clean: logo
		@echo "\033[31m------------>\033[0m               Suppression .o"
		@rm -rf $(LOBJ)
fclean: clean
		@echo "\033[31m------------>\033[0m        Suppression programme"
		@rm -rf $(NAME) $(GNL)
re: fclean all

.PHONY: clean fclean re all mouli1 mouli2
