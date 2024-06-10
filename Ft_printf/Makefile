CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS =\
ft_unsigned_nbr.c\
ft_putchar.c\
ft_xbase16.c\
ft_printf.c\
ft_putnbr.c\
ft_putstr.c\

OBJCTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJCTS)
	ar rc $(NAME) $(OBJCTS)

%.o:%.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJCTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
