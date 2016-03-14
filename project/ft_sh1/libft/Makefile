# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylarbi <ylarbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 14:26:00 by ylarbi            #+#    #+#              #
#*   Updated: 2016/03/10 15:00:16 by ylarbi           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

H_DIR	= ../inc
C_DIR	= .
O_DIR	= ../obj

FLAGS	= -Wall -Wextra -Werror -O2
LINKS	= -I$(H_DIR)
DEBUG	= 0

C_FILES	= $(shell find $(C_DIR) -type f -print | grep "\.c")
C_DIRS	= $(shell find $(C_DIR) -type d -print)

O_FILES	= $(C_FILES:$(C_DIR)/%.c=$(O_DIR)/%.o)
O_DIRS	= $(C_DIRS:$(C_DIR)/%=$(O_DIR)/%)

all: logo
	@if [ "$(DEBUG)" -eq "1" ]; then \
		make -j4 _debug $(NAME); else \
		make -j4 $(NAME); fi
logo:
	@printf "%-35slibft\n"

mkdir:
	@mkdir -p $(O_DIRS) $(O_DIR) 2> /dev/null || echo "" > /dev/null\
	&& printf "\033[0;34m%-34s \033[1;30m<<--\033[0;0m\033[1;34m\tObject folder create\033[0;0m\n" "$(O_DIR)"\
	|| (printf "\033[0;32m%-34s \033[1;30m<<--\033[0;0m\033[1;33m\tObject folder create\033[0;0m\n" "$(O_DIR)"\
		&& exit 1)

$(NAME): $(O_FILES:.c=.o)
	@ar rcs $@ $^ && printf "\033[0;33m" || printf "\031[0;31m"
	@printf "%-34s \033[1;30m<<--\033[0;0m\033[1;33m\tLibrary create\033[0;0m\n" "$@"

$(O_DIR)/%.o: $(C_DIR)/%.c mkdir
	@gcc $(FLAGS) $(LINKS) -o $@ -c $< \
	&& printf "\033[0;0m%-34s\033[1;30m -->>\t\033[0;32m$@\033[0;0m\n" "$<" \
	|| (printf "\033[0;0m%-34s\033[1;30m -->>\t\033[0;31m$@\033[0;0m\n" "$<" \
		&& exit 1)

debug: _debug all

clean: logo
	@rm $(O_FILES) 2> /dev/null || echo "" > /dev/null
	@printf "\033[0;31m%-34s\033[1;30m <<--\t\033[1;31mDelete folder\033[0;0m\n" "$(O_DIR)"
	@rmdir $(O_DIRS) $(O_DIR) 2> /dev/null || echo "" > /dev/null

fclean: clean
	@rm $(NAME) 2> /dev/null || echo "" > /dev/null

re: fclean all

rebug: fclean debug

_debug:
	$(eval FLAGS = -Wall -Wextra -g -D DEBUG_MODE)
	$(eval DEBUG = 1)

.PHONY: all debug clean fclean re rebug update _debug
