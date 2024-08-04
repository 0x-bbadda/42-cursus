CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = philo

RM = rm -rf

RED = \033[0;31m

RESET = \033[0m

CYAN = \033[0;36m

YELLOW = \033[0;33m

SRCS = 	philo.c philo_utils.c philo_utils2.c\
		tools.c make_things.c init_data.c init_mutex.c\

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