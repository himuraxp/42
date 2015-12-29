# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 14:26:00 by ylarbi            #+#    #+#              #
#*   Updated: 2015/12/28 17:05:07 by ylarbi           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC  = `ls | grep "\.c" | grep "ft_"`
OBJ  = `ls | grep "\.o" | grep "ft_"`
FLAGS =  -Wall -Wextra -Werror
INCLUDE = libft.h

all: $(NAME)

$(NAME): logo
		@gcc $(FLAGS) -I$(INCLUDE) -c $(SRC)
		@echo "\033[32m------------>\033[0m        Compilation programme"
		@ar rc $(NAME) $(OBJ)
		@echo "\033[36m------------>\033[0m           Creation librairie"
		@ranlib $(NAME)
		@echo "\033[36m------------>\033[0m     Creation index librairie"
logo:
		@echo "\n"
		@echo "\033[31m          :::         :::::::::::  :::::::::     \033[0m"
		@echo "\033[31m         :+:             :+:      :+:    :+:     \033[0m"
		@echo "\033[32m        +:+             +:+      +:+    +:+      \033[0m"
		@echo "\033[32m       +#+             +#+      +#++:++#+        \033[0m"
		@echo "\033[33m      +#+              +#+     +#+    +#+        \033[0m"
		@echo "\033[33m     #+#             #+#      #+#    #+#         \033[0m"
		@echo "\033[36m    ##########  ###########  #########           \033[0m"
		@echo "\n"
		@echo "\033[36m                            Libft - ylarbi\033[0m"
clean: logo
		@echo "\033[31m------------>\033[0m               Suppression .o"
		@rm -rf $(OBJ)
fclean: clean
		@echo "\033[31m------------>\033[0m        Suppression programme"
		@rm -rf $(NAME)
re: fclean all

.PHONY: clean fclean re all logo
