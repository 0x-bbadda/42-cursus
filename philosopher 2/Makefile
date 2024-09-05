CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = philo

RM = rm -rf

RED = \033[0;31m


SRCS = 	philo.c philo_utils.c philo_utils2.c print_things.c\
		routine.c create_things.c init_things.c check_things.c\

OBJS = $(SRCS: .c = .o )

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(OBJS)  -o  $(NAME)

%.o:%.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) *.o

fclean : clean
	$(RM) $(NAME)

re : clean all