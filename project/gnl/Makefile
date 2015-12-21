# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 14:26:00 by ylarbi            #+#    #+#              #
#*   Updated: 2015/12/09 17:14:39 by ylarbi           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC  = `ls | grep "\.c" | grep "ft_"`
OBJ  = `ls | grep "\.o" | grep "ft_"`
FLAGS =  -Wall -Wextra -Werror
INCLUDE = libft.h

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) -I$(INCLUDE) -c $(SRC)
		@echo "Compilation programme"
		@ar rc $(NAME) $(OBJ)
		@echo "Creation librairie"
		@ranlib $(NAME)
		@echo "Creation index librairie"
clean:
		@echo "Suppression .o"
		@rm -rf $(OBJ)
fclean: clean
		@echo "Suppression programme"
		@rm -rf $(NAME)
re: fclean all

.PHONY: clean fclean re
