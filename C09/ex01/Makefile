CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = srcs
CFILES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
INCS = includes
SRCS = $(addprefix $(SRCDIR)/,$(CFILES))
OBJS = $(SRCS:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCS) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:  all clean fclean re
