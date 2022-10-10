NAME = libftprintf.a
SRC = ft_printf.c ft_printf_utils.c main.c
OBJS = $(SRC:.c=.o)
AR = ar rcs
CC = gcc -o
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(NAME) $(OBJS)

%.o: %.c
	gcc $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
