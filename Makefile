# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 18:34:44 by dduvivie          #+#    #+#              #
#    Updated: 2022/06/01 18:34:46 by dduvivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk
SERVER		= server
CLIENT		= client
LIBFT		= libft
LIB			= libft/libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SERVER_SRC	= server.c
SERVER_OBJ	= $(SERVER_SRC:.c=.o)	
CLIENT_SRC	= client.c 
CLIENT_OBJ	= $(CLIENT_SRC:.c=.o)
OBJS		= $(SERVER_OBJ) $(CLIENT_OBJ)


all: $(NAME)

$(NAME): comp_libft comp_server comp_client

comp_libft:
	@ $(MAKE) -C $(LIBFT) all

comp_server:
	@ $(CC) $(CFLAGS) -c $(SERVER_SRC)
	@ $(CC) -o $(SERVER) $(SERVER_OBJ) $(LIB)

comp_client: $(CLIENT_SRC)
	@ $(CC) $(CFLAGS) -c $(CLIENT_SRC)
	@ $(CC) -o $(CLIENT) $(CLIENT_OBJ) $(LIB)

clean:
	@ $(MAKE) -C $(LIBFT) clean
	@ rm -f $(OBJS)

fclean: clean
	@ rm -f $(SERVER) $(CLIENT)
	@ $(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all comp_libft comp_server comp_client clean fclean re