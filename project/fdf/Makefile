# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 14:26:00 by ylarbi            #+#    #+#              #
#    Updated: 2016/03/03 18:24:12 by ylarbi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE		=	fdf
NAME	=	fdf.a
FLAGS	=	-Wall -Wextra -Werror

SRCNAME =	init.c fdf.c error.c verif.c draw.c color.c key.c tools.c trace.c
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
		@gcc $(FLAGS) $(INCLUDE) $(LIB) $(MLX) -o $(EXE) $(SRC)
		@clear
		@printf "\033[0;36m%-34s\033[1;30m <<--\t\033[1;36mCompiled program\033[0;0m\n" "$(EXE)"

logo:
		@echo "\033[2J"
		@echo "\033[200A"
		@echo "\033[31m                :::::::::: :::::::::  ::::::::::            \033[0m"
		@echo "\033[31m               :+:        :+:    :+: :+:                    \033[0m"
		@echo "\033[32m              +:+        +:+    +:+ +:+                     \033[0m"
		@echo "\033[32m             :#::+::#   +#+    +:+ :#::+::#                 \033[0m"
		@echo "\033[33m            #+#        #+#    #+# #+#                       \033[0m"
		@echo "\033[33m           #+#        #+#    #+# #+#                        \033[0m"
		@echo "\033[36m          ###        ########   ###                   ylarbi\033[0m"
		@echo "\n"
		@printf "%-37sfdf\n"
clean: logo
		@printf "\033[0;31m%-34s\033[1;30m <<--\t\033[1;31mDelete folder\033[0;0m\n" "$(OBJ)"
		@rm -rf $(OBJ) 2> /dev/null || echo "" > /dev/null

fclean: clean
	@printf "\033[0;31m%-34s\033[1;30m <<--\t\033[1;31mDelete library\033[0;0m\n" "$(NAME)"
	@printf "\033[0;31m%-34s\033[1;30m <<--\t\033[1;31mDelete program\033[0;0m\n" "$(EXE)"
	@rm -rf $(NAME) $(EXE)
re: fclean all

.PHONY: clean fclean re all logo
