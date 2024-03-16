NAME = server client
NAME_BONUS = server_bonus client_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
FT_PRINTF = ./ft_printf/libftprintf.a
RM = rm -rf

SERVER_SRCS = server.c
CLIENT_SRCS = client.c
SERVER_BONUS_SRCS = server_bonus.c
CLIENT_BONUS_SRCS = client_bonus.c

all: $(NAME)
bonus: $(NAME_BONUS)

		
$(FT_PRINTF):
		$(MAKE) --no-print-directory -C ./ft_printf
		
$(NAME):  $(FT_PRINTF) $(SERVER_SRCS)  $(CLIENT_SRCS) 
	$(CC) $(CFLAGS) $(SERVER_SRCS)  $(FT_PRINTF) -o server
	$(CC) $(CFLAGS) $(CLIENT_SRCS)  $(FT_PRINTF) -o client


$(NAME_BONUS): $(SERVER_BONUS_SRCS) $(CLIENT_BONUS_SRCS)  $(FT_PRINTF)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_SRCS)  $(FT_PRINTF) -o client_bonus
	$(CC) $(CFLAGS) $(SERVER_BONUS_SRCS)  $(FT_PRINTF) -o server_bonus


clean:
	$(MAKE) clean --no-print-directory -C ./ft_printf

fclean: clean
	$(MAKE) fclean --no-print-directory -C ./ft_printf
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.SILENT:
	