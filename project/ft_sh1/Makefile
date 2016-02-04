# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 14:26:00 by ylarbi            #+#    #+#              #
#    Updated: 2016/02/03 18:12:35 by ylarbi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft/libft.a
SRCNAME	= 	ft_sh1.c get_cmd.c env.c process.c cd.c init.c env_opt.c access.c\
			prompt.c
SRCPATH =	src/
SRC		=	$(addprefix $(SRCPATH)/,$(SRCNAME))
OBJ		=	obj/
FLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-Iinc
LIB		=	-Llibft/ -lft
EXE		=	ft_sh1
LIBFT	=	-Clibft/

all: $(NAME)

$(NAME): logo
		@make $(LIBFT)
		@gcc $(FLAGS) $(INCLUDE) $(LIB) -o $(EXE) $(SRC)
		@clear
		@printf "\033[0;36m%-34s\033[1;30m <<--\t\033[1;36mCompiled program\033[0;0m\n" "$(EXE)"

logo:
		@echo "\033[2J"
		@echo "\033[200A"
		@echo "\033[31m      :::::::::: :::::::::::           ::::::::  :::    :::   ::: \033[0m"
		@echo "\033[31m     :+:            :+:              :+:    :+: :+:    :+: :+:+:  \033[0m"
		@echo "\033[32m    +:+            +:+              +:+        +:+    +:+   +:+   \033[0m"
		@echo "\033[32m   :#::+::#       +#+              +#++:++#++ +#++:++#++   +#+    \033[0m"
		@echo "\033[33m  +#+            +#+                     +#+ +#+    +#+   +#+     \033[0m"
		@echo "\033[33m #+#            #+#              #+#    #+# #+#    #+#   #+#      \033[0m"
		@echo "\033[36m###            ###    ########## ########  ###    ### ######ylarbi\033[0m"
		@echo "\n"
		@printf "%-35sft_ls\n"

clean: logo
		@printf "\033[0;31m%-34s\033[1;30m <<--\t\033[1;31mDelete folder\033[0;0m\n" "$(OBJ)"
		@rm -rf $(OBJ) 2> /dev/null || echo "" > /dev/null

fclean: clean
		@printf "\033[0;31m%-34s\033[1;30m <<--\t\033[1;31mDelete library\033[0;0m\n" "$(NAME)"
		@printf "\033[0;31m%-34s\033[1;30m <<--\t\033[1;31mDelete program\033[0;0m\n" "$(EXE)"
		@rm -rf $(NAME) $(EXE)
re: fclean all

.PHONY: clean fclean re all logo
