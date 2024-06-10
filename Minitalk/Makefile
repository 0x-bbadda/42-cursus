CLIENT= client
SERVER= server
BONUS_SERVER = server_bonus
BONUS_CLIENT = client_bonus

CC = cc

RM = rm -rf

CFLAGS=  -Wall -Wextra -Werror

SERVER_SRCS = ./mandatory/server.c ./mandatory/utilits.c
CLIENT_SRCS = ./mandatory/client.c ./mandatory/utilits.c
BONUS_SERVER_SRCS = ./bonus/server_bonus.c ./bonus/utilits_bonus.c
BBONUS_CLIENT_SRCS = ./bonus/client_bonus.c ./bonus/utilits_bonus.c

OBJS_S= ${SERVER_SRCS:.c=.o}
OBJS_C= ${CLIENT_SRCS:.c=.o}
OBJS_BONUS_S= ${BONUS_SERVER_SRCS:.c=.o}
OBJS_BONUS_C= ${BBONUS_CLIENT_SRCS:.c=.o}

all :  $(CLIENT) $(SERVER) 
bonus : $(BONUS_CLIENT) $(BONUS_SERVER)

$(CLIENT): $(OBJS_C)
	@$(CC) $(CFLAGS) $(OBJS_C) -o $(CLIENT)

$(SERVER): $(OBJS_S)
	@$(CC) $(CFLAGS) $(OBJS_S) -o $(SERVER)

$(BONUS_CLIENT): $(OBJS_BONUS_C)
	@$(CC) $(CFLAGS) $(OBJS_BONUS_C) -o $(BONUS_CLIENT)

$(BONUS_SERVER): $(OBJS_BONUS_S)
	@$(CC) $(CFLAGS) $(OBJS_BONUS_S) -o $(BONUS_SERVER)

%.o:%.c minitalk.h minitalk_bonus.h
	@$(CC) $(CFLAGS)  -c $< -o $@

clean:
	@$(RM) ./mandatory/*.o
	@$(RM) ./bonus/*.o

fclean: clean
	@$(RM) $(CLIENT)
	@$(RM) $(SERVER)
	@$(RM) $(BONUS_CLIENT)
	@$(RM) $(BONUS_SERVER)

re: fclean all