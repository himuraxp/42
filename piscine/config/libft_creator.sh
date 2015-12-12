#!/bin/sh
gcc -c -Wall -Werror -Wextra ft*.c && ar rc ~/libft.a ft*.o && ranlib ~/libft.a | rm *.o

