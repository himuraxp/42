# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 14:26:00 by ylarbi            #+#    #+#              #
#*   Updated: 2015/12/30 10:25:24 by ylarbi           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
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
SRCPATH = .
LBSRC	= $(addprefix $(SRCPATH)/,$(SRCNAME))
OBJNAME = $(SRCNAME:.c=.o)
OBJPATH = obj/
LBOBJ	= $(addprefix $(OBJPATH)/,$(OBJNAME))
FLAGS	=  -Wall -Wextra -Werror
INCLUDE	= -Ilibft.h
LIB		= -L. -lft

all: $(NAME)

$(NAME): logo lib

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
lib:
		@gcc -c $(LBSRC)
		@echo "\033[36m------------>\033[0m          Compilation library"
		@mv $(OBJNAME) $(OBJPATH)
		@echo "\033[33m------------>\033[0m        Move .o to obj folder"
		@ar rc $(NAME) $(LBOBJ)
		@echo "\033[36m------------>\033[0m             Creation library"
		@ranlib $(NAME)
		@echo "\033[36m------------>\033[0m    Creation of library index"

clean: logo
		@echo "\033[31m------------>\033[0m               Suppression .o"
		@rm -rf $(LBOBJ)
fclean: clean
		@echo "\033[31m------------>\033[0m          Suppression program"
		@rm -rf $(NAME)
re: fclean all

.PHONY: clean fclean re all logo lib
