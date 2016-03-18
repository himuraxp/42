# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 14:26:00 by ylarbi            #+#    #+#              #
#    Updated: 2016/03/18 10:16:19 by ylarbi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE		=	fractol
NAME	=	fractol.a
FLAGS	=	-Wall -Wextra -Werror

SRCNAME =	fractol.c hook.c draw.c error.c mandelbrot.c menu.c julia.c carpet.c
SRCPATH =	src/
SRC		=	$(addprefix $(SRCPATH)/,$(SRCNAME))
OBJ		=	./obj
INCLUDE	=	-Iinc

LIB		=	-Llibft/ -lft
LIBFT	=	-Clibft/

MLX		=	-L/usr/lib/ -I/usr/include -lmlx -framework OpenGL -framework AppKit
MYMLX	=	-I/minilibx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

relink:
		@if [ -a $(OBJ) ]; then\
	 	printf "\033[0;31m%-34s\033[1;30m <<--\t\033[1;31mError Relink\033[0;0m\n" "$(OBJ)"; exit 1; fi


$(NAME): logo relink minilibx
		@make $(LIBFT)
		@gcc $(FLAGS) $(INCLUDE) $(LIB) $(MLX) -o $(EXE) $(SRC)
		@clear
		@printf "\033[0;36m%-34s\033[1;30m <<--\t\033[1;36mCompiled program\033[0;0m\n" "$(EXE)"

logo:
		@echo "\033[2J"
		@echo "\033[200A"
		@echo "\033[31m      :::::::::: :::::::::      :::      :::::::: ::::::::::: ::: ::::::::  :::  \033[0m"
		@echo "\033[31m     :+:        :+:    :+:   :+: :+:   :+:    :+:    :+:     :+ :+:    :+: :+:   \033[0m"
		@echo "\033[32m    +:+        +:+    +:+  +:+   +:+  +:+           +:+        +:+    +:+ +:+    \033[0m"
		@echo "\033[32m   :#::+::#   +#++:++#:  +#++:++#++: +#+           +#+        +#+    +:+ +#+     \033[0m"
		@echo "\033[33m  +#+        +#+    +#+ +#+     +#+ +#+           +#+        +#+    +#+ +#+      \033[0m"
		@echo "\033[33m #+#        #+#    #+# #+#     #+# #+#    #+#    #+#        #+#    #+# #+#       \033[0m"
		@echo "\033[36m###        ###    ### ###     ###  ########     ###         ########  ####ylarbi \033[0m"
		@echo "\n"
		@printf "%-35sfractol\n"
clean: logo
		@printf "\033[0;31m%-34s\033[1;30m <<--\t\033[1;31mDelete folder\033[0;0m\n" "$(OBJ)"
		@rm -rf $(OBJ) 2> /dev/null || echo "" > /dev/null

fclean: clean
	@printf "\033[0;31m%-34s\033[1;30m <<--\t\033[1;31mDelete library\033[0;0m\n" "$(NAME)"
	@printf "\033[0;31m%-34s\033[1;30m <<--\t\033[1;31mDelete program\033[0;0m\n" "$(EXE)"
	@rm -rf $(NAME) $(EXE)
re: fclean all

.PHONY: clean fclean re all logo
