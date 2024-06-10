NAME = push_swap

CHECKER = checker

CC = gcc 

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

SRCS = 	push_swap.c\
		simple_sort.c\
		linked_list_utils.c\
		push_swap_utils.c\
		instructions_push.c\
		instructions_rotate.c\
		instructions_rrotate.c\
		instructions_swap.c\
		get_helper.c\
		range.c\

B_SRCS = checker_bonus.c\
		 checker_utils_bonus.c\
		 checker_resource_bonus.c\
		 checker_s_bonus.c\
		 checker_r_bonus.c\
		 checker_rr_bonus.c\
		 checker_p_bonus.c\


OBJS = ${SRCS:.c=.o}
B_OBJS = ${B_SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@${MAKE} -C ./libft
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

bonus: $(CHECKER)

$(CHECKER):$(B_OBJS)
		@${MAKE} -C ./libft
		$(CC) $(CFLAGS) $(B_OBJS) ./libft/libft.a -o $(CHECKER)

%.o:%.c push_swap.h checker_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}
	@${RM} ${B_OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${CHECKER}

re: fclean all


