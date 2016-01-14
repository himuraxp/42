# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 14:26:00 by ylarbi            #+#    #+#              #
#*   Updated: 2016/01/14 21:05:31 by ylarbi           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME	= fdf.a
SRCNAME =	main.c fdf.c get_next_line.c init.c color.c move.c parse.c draw.c \
			point.c
SRCPATH = src/
SRC		= $(addprefix $(SRCPATH)/,$(SRCNAME))
FLAGS	= -Wall -Wextra -Werror
INCLUDE	= -Iinc
LIB		= -Llibft/ -lft
EXE		= fdf
LIBFT	= -Clibft/
MLX		= -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): logo minilibx
		@make $(LIBFT)
		@gcc $(FLAGS) $(INCLUDE) $(LIB) $(MLX) -o $(EXE) $(SRC)
		@echo "\033[32m------------>          Program compilation\033[0m"

logo:
		@echo "\n"
		@echo "\033[31m       :::::::::: :::::::::  ::::::::::   \033[0m"
		@echo "\033[31m      :+:        :+:    :+: :+:           \033[0m"
		@echo "\033[32m     +:+        +:+    +:+ +:+            \033[0m"
		@echo "\033[32m    :#::+::#   +#+    +:+ :#::+::#        \033[0m"
		@echo "\033[33m   #+#        #+#    #+# #+#              \033[0m"
		@echo "\033[33m  #+#        #+#    #+# #+#               \033[0m"
		@echo "\033[36m ###        #########  ###                \033[0m"
		@echo "\033[36m                              fdf - ylarbi\033[0m"
		@echo "\n"
clean: logo
		@echo "\033[31m------------>          fdf  Suppression .o\033[0m"
		@rm -rf $(OBJPATH)

fclean: clean
		@echo "\033[31m------------>      fdf Suppression program\033[0m"
		@rm -rf $(NAME) $(EXE)

re: fclean all

.PHONY: clean fclean re all logo
