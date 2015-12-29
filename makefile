# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 14:26:00 by ylarbi            #+#    #+#              #
#*   Updated: 2015/12/28 19:09:53 by ylarbi           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME		=	gnl
SRC_PATH	=	libft/
SRC_NAME	=	ft_lstiter.c	\
				ft_lstmap.c		\
				ft_lstnew.c		\
				ft_lstadd.c		\
				ft_lstdel.c		\
				ft_lstdelone.c	\
				ft_atoi.c		\
				ft_bzero.c		\
				ft_isalnum.c	\
				ft_isalpha.c	\
				ft_isascii.c	\
				ft_isdigit.c	\
				ft_isprint.c	\
				ft_iswhite.c	\
				ft_itoa.c		\
				ft_memalloc.c	\
				ft_memccpy.c	\
				ft_memchr.c		\
				ft_memcmp.c		\
				ft_memcpy.c		\
				ft_memdel.c		\
				ft_memmove.c	\
				ft_memset.c		\
				ft_putchar.c	\
				ft_putchar_fd.c	\
				ft_putendl.c	\
				ft_putendl_fd.c	\
				ft_putnbr.c		\
				ft_putnbr_fd.c	\
				ft_putstr.c		\
				ft_putstr_fd.c	\
				ft_strequ.c		\
				ft_strnew.c		\
				ft_striter.c	\
				ft_strnstr.c	\
				ft_striteri.c	\
				ft_strrchr.c	\
				ft_strjoin.c	\
				ft_strsplit.c	\
				ft_strlcat.c	\
				ft_strstr.c		\
				ft_strlen.c		\
				ft_strsub.c		\
				ft_strcat.c		\
				ft_strmap.c		\
				ft_strtrim.c	\
				ft_strchr.c		\
				ft_strmapi.c	\
				ft_strclr.c		\
				ft_strncat.c	\
				ft_strcmp.c		\
				ft_strncmp.c	\
				ft_strcpy.c		\
				ft_strncpy.c	\
				ft_strdel.c		\
				ft_strndup.c	\
				ft_strdup.c		\
				ft_strnequ.c	\
				ft_tolower.c	\
				ft_toupper.c	\
OBJ_PATH	=	libft
OBJ_NAME	=	$(SRC_NAME:.c=.o)
CPP_FLAGS	=	-Ilibft
LD_FLAGS	=	-Llibft
LD_LIBS		=	-Lft
C_FLAGS		=	-Wall -Wextra -Werror
CC			=	clang
SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ) logo
		@$(CC) $(LD_FLAGS) $(LD_LIBS) $^ -o $@
		@echo "\033[36m------------>\033[0m             Search librairie"
		@echo "\033[36m------------>\033[0m              Librairie found"
		@echo "\033[32m------------>\033[0m        Compilation programme"
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		@$(CC) $(C_FLAGS) $(CPP_FLAGS) -o $@ -c $<
		@echo "\033[33m------------>\033[0m      Create temporary folder"
		@echo "\033[32m------------>\033[0m        Compilation programme"
logo:
		@echo "\n"
		@echo "\033[31m          ::::::::   ::::    :::  :::     \033[0m"
		@echo "\033[31m        :+:    :+:  :+:+:   :+:  :+:      \033[0m"
		@echo "\033[32m       +:+         :+:+:+  +:+  +:+       \033[0m"
		@echo "\033[32m      :#:         +#+ +:+ +#+  +#+        \033[0m"
		@echo "\033[33m     +#+   +#+#  +#+  +#+#+#  +#+         \033[0m"
		@echo "\033[33m    #+#    #+#  #+#   #+#+#  #+#          \033[0m"
		@echo "\033[36m    ########   ###    ####  ##########    \033[0m"
		@echo "\n"
		@echo "\033[36m                    Get Next Line - ylarbi\033[0m"
clean: logo
		@rm -fv $(OBJ)
		@echo "\033[31m------------>\033[0m                Clean file .o"
		@rmdir $(OBJ_PATH) 2> /dev/null || true
		@echo "\033[31m------------>\033[0m             Clear obj folder"
fclean: clean
		@echo "\033[31m------------>\033[0m        Suppression programme"
		@rm -fv $(NAME)
re: fclean all

.PHONY: clean fclean re all logo
