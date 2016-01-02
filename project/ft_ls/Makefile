# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 14:26:00 by ylarbi            #+#    #+#              #
#*   Updated: 2016/01/02 13:39:59 by ylarbi           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME	= libft/libft.a
SRC		= `ls | grep "\.c"`
SRCNAME =	ft_lstdelone.c  ft_putchar_fd.c ft_strdup.c     ft_strnequ.c \
			ft_lstiter.c    ft_putendl.c    ft_strequ.c     ft_strnew.c  \
			ft_atoi.c       ft_lstmap.c     ft_putendl_fd.c ft_striter.c \
			ft_strnstr.c    ft_strrchr.c    ft_isalnum.c    ft_memalloc.c\
			ft_bzero.c      ft_lstnew.c     ft_putnbr.c     ft_striteri.c\
			ft_putnbr_fd.c  ft_strjoin.c    ft_strsplit.c   ft_strstr.c  \
			ft_isalpha.c    ft_memccpy.c    ft_putstr.c     ft_strlcat.c \
			ft_isascii.c    ft_memchr.c     ft_putstr_fd.c  ft_strlen.c  \
			ft_strsub.c     ft_toupper.c    ft_strtrim.c    ft_tolower.c \
			ft_isdigit.c    ft_memcmp.c     ft_strcat.c     ft_strmap.c  \
			ft_isprint.c    ft_memcpy.c     ft_strchr.c     ft_strmapi.c \
			ft_iswhite.c    ft_memdel.c     ft_strclr.c     ft_strncat.c \
			ft_itoa.c       ft_memmove.c    ft_strcmp.c     ft_strncmp.c \
			ft_lstadd.c     ft_memset.c     ft_strcpy.c     ft_strncpy.c \
			ft_lstdel.c     ft_putchar.c    ft_strdel.c     ft_strndup.c
SRCPATH = libft/
LBSRC	= $(addprefix $(SRCPATH)/,$(SRCNAME))
OBJNAME = $(SRCNAME:.c=.o)
OBJPATH = libft/obj/
LBOBJ	= $(addprefix $(OBJPATH)/,$(OBJNAME))
FLAGS	= -Wall -Wextra -Werror
INCLUDE	= -Ilibft/libft.h
LIB		= -Llibft/ -lft
EXE		= ft_ls
LIBFT	= -Clibft/

all: $(NAME)

$(NAME): logo
		@make $(LIBFT)
		@gcc $(FLAGS) $(INCLUDE) $(SRC) $(LIB) -o $(EXE)
		@echo "\033[32m------------>          Program compilation\033[0m"

logo:
		# @echo "\033[2j"
		# @echo "\033[10000A"
		@echo "\n"
		@echo "\033[31m               :::        ::::::::        \033[0m"
		@echo "\033[31m              :+:       :+:    :+:        \033[0m"
		@echo "\033[32m             +:+       +:+                \033[0m"
		@echo "\033[32m            +#+       +#++:++#++          \033[0m"
		@echo "\033[33m           +#+              +#+           \033[0m"
		@echo "\033[33m          #+#       #+#    #+#            \033[0m"
		@echo "\033[36m         ########## ########              \033[0m"
		@echo "\033[36m                            ft_ls - ylarbi\033[0m"
		@echo "\n"

lib:
		@gcc -c $(LBSRC)
		@echo "\033[36m------------>          Compilation library\033[0m"
		@mkdir $(OBJPATH) 2> /dev/null || true
		@echo "\033[33m------------>            Create obj folder\033[0m"
		@mv $(OBJNAME) $(OBJPATH)
		@echo "\033[33m------------>        Move .o to obj folder\033[0m"
		@ar rc $(NAME) $(LBOBJ)
		@echo "\033[36m------------>             Creation library\033[0m"
		@ranlib $(NAME)
		@echo "\033[36m------------>    Creation of library index\033[0m"

clean: logo
		@echo "\033[31m------------>               Suppression .o\033[0m"
		@rm -rf $(OBJPATH)
fclean: clean
		@echo "\033[31m------------>          Suppression program\033[0m"
		@rm -rf $(NAME) $(EXE)
re: fclean all

.PHONY: clean fclean re all logo lib
