NAME= cub3d

CFLAGS=  -Wall -Wextra -Werror -fsanitize=address -g

SRCS= 	./mandatory/main.c ./mandatory/utils.c ./mandatory/get_next_line.c\
./mandatory/get_next_line_utils.c

GREEN = "\033[32m"

OBJS= ${SRCS:.c=.o}

all :  $(NAME)

$(NAME): $(OBJS)
	@echo ${GREEN}"Compiling ${NAME}..."
	@$(CC) $(CFLAGS) $(OBJS) -framework OpenGL -framework AppKit -lmlx  -o $(NAME)
	@echo "Successfully compiled ${NAME}!"

%.o:%.c ./include/*.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)

fclean: clean
	@rm -rf $(NAME)

re: clean all