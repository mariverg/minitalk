# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariverg <mariverg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 14:21:44 by mariverg          #+#    #+#              #
#    Updated: 2024/06/11 11:43:29 by mariverg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME = client
SERVER_NAME = server
CLIENT_BONUS_NAME = client_bonus
SERVER_BONUS_NAME = server_bonus
CLIENT_SOURCES = client.c
SERVER_SOURCES = server.c
CLIENT_BONUS_SOURCES = client_bonus.c
SERVER_BONUS_SOURCES = server_bonus.c

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I . -I include -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR)

CC = $(shell which cc clang gcc | head -n 1)
CFLAGS = -Wall -Wextra -Werror

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(LIBFT) $(FT_PRINTF)
	@$(CC)  $(INCLUDES) $(CLIENT_SOURCES) $(LIBFT) $(FT_PRINTF) $(CFLAGS) -o $(CLIENT_NAME)

$(SERVER_NAME): $(LIBFT) $(FT_PRINTF)
	@$(CC)  $(INCLUDES) $(SERVER_SOURCES)  $(LIBFT) $(FT_PRINTF) $(CFLAGS) -o $(SERVER_NAME)

$(CLIENT_BONUS_NAME): $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(INCLUDES) $(CLIENT_BONUS_SOURCES) $(LIBFT) $(FT_PRINTF) -o $(CLIENT_BONUS_NAME)

$(SERVER_BONUS_NAME): $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(INCLUDES) $(SERVER_BONUS_SOURCES)  $(LIBFT) $(FT_PRINTF) -o $(SERVER_BONUS_NAME)

bonus: $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all