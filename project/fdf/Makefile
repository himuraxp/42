# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 14:26:00 by ylarbi            #+#    #+#              #
#    Updated: 2016/02/26 15:45:32 by ylarbi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE		=	fdf
NAME	=	fdf.a
FLAGS	=	-Wall -Wextra -Werror

SRCNAME =	init.c fdf.c error.c verif.c
SRCPATH =	src/
SRC		=	$(addprefix $(SRCPATH)/,$(SRCNAME))
OBJ		=	./obj
INCLUDE	=	-Iinc

LIB		=	-Llibft/ -lft
LIBFT	=	-Clibft/

MLX		=	-L/usr/lib/ -I/usr/include -lmlx -framework OpenGL -framework AppKit
MYMLX	=	-I/minilibx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): logo minilibx
		@make $(LIBFT)
		@gcc $(FLAGS) $(INCLUDE) $(LIB) $(MYMLX) -o $(EXE) $(SRC)
		@echo "\033[32m------------>          Program compilation\033[0m"

logo:
		@echo "\033[2J"
		@echo "\033[200A"
		@echo "\033[31m       :::::::::: :::::::::  ::::::::::   \033[0m"
		@echo "\033[31m      :+:        :+:    :+: :+:           \033[0m"
		@echo "\033[32m     +:+        +:+    +:+ +:+            \033[0m"
		@echo "\033[32m    :#::+::#   +#+    +:+ :#::+::#        \033[0m"
		@echo "\033[33m   #+#        #+#    #+# #+#              \033[0m"
		@echo "\033[33m  #+#        #+#    #+# #+#               \033[0m"
		@echo "\033[36m ###        #########  ###          ylarbi\033[0m"
		@echo "\n"
		@echo "                                       fdf"
clean: logo
		@echo "\033[31m------------>          fdf  Suppression .o\033[0m"
		@rm -rf $(OBJ)

fclean: clean
		@echo "\033[31m------------>      fdf Suppression program\033[0m"
		@rm -rf $(NAME) $(EXE)

re: fclean all

.PHONY: clean fclean re all logo
