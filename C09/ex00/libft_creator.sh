#!/bin/sh

gcc -Wall -Wextra -Werror -c *.c
ar rcs libft.a *.o
find . -type f -name "*.o" -delete