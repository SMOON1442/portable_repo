CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
SRCS = ft_printf.c \
	   ft_printf_utils.c \
	   srcs/ft_putchar.c \
	   srcs/ft_putstr.c \
	   srcs/ft_putnbr.c \
	   srcs/ft_putunbr.c \
	   srcs/ft_puthex.c \
	   srcs/ft_putupperhex.c \
	   srcs/ft_putaddr.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o && rm -f */*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
