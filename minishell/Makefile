CC = cc

NAME = minishell

SRC = minishell.c minishell_utils.c minishell_utils2.c ft_split.c

OBJ = $(SRC: .c = .o)

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) -lreadline -g $(OBJ) -fsanitize=address -o $(NAME)

%.o:%.c minishell.h
	$(CC) -c $< -o $@

clean :
	$(RM) *.o

fclean : clean
	$(RM) $(NAME)

re : fclean all