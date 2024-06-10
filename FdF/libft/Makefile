# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/24 14:52:44 by bbadda            #+#    #+#              #
#    Updated: 2024/03/24 02:32:34 by bbadda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRCS = ft_strchr.c ft_memset.c ft_strncmp.c ft_isalpha.c ft_toupper.c ft_tolower.c ft_strlen.c \
ft_strrchr.c ft_memchr.c ft_isprint.c ft_isdigit.c ft_isascii.c ft_isalnum.c ft_bzero.c \
ft_memcmp.c ft_strnstr.c ft_memcpy.c ft_memmove.c ft_strlcat.c ft_atoi.c ft_calloc.c ft_strdup.c\
ft_substr.c ft_strjoin.c ft_strtrim.c  ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c\
ft_putnbr_fd.c ft_putendl_fd.c ft_striteri.c ft_strmapi.c ft_strlcpy.c ft_split.c get_next_line.c \
get_next_line_utils.c

B_SRCS =  ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
ft_lstiter_bonus.c ft_lstmap_bonus.c 

OBJS =$(SRCS:.c=.o)

B_OBJS =$(B_SRCS:.c=.o)

all:$(NAME)

$(NAME):$(OBJS)
	@ar rcs $(NAME) $(OBJS)

bonus:$(B_OBJS)
	@ar rc $(NAME) $(B_OBJS)

%.o:%.c libft.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(B_OBJS)

fclean:clean
	@rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re bonus