NAME= fdf

CFLAGS=  -Wall -Wextra -Werror

SRCS= 	./mandatory/fdf.c ./mandatory/fdf_utils.c \
		./mandatory/fdf_utils2.c ./mandatory/fdf_utils3.c \
		./mandatory/mlx.c ./mandatory/mlx_keys.c ./mandatory/mlx2.c

GREEN = "\033[32m"

OBJS= ${SRCS:.c=.o}

all :  $(NAME)

$(NAME): $(OBJS)
	@echo ${GREEN}"Compiling ${NAME}..."
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) -framework OpenGL -framework AppKit -lmlx ./libft/libft.a -o $(NAME)
	@echo "Successfully compiled ${NAME}!"

%.o:%.c ./include/*.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@${MAKE} -C ./libft fclean
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)

fclean: clean
	@rm -rf $(NAME)

re: clean all