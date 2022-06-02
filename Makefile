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

SERVER		= server
CLIENT		= client
#NAME		= $(SERVER)
LIBFT		= libft
LIB			= libft/libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SERVER_SRC	= server.c
SERVER_OBJ	= $(SERVER_SRC:.c=.o)	
CLIENT_SRC	= client.c 
CLIENT_OBJ	= $(CLIENT_SRC:.c=.o)
OBJS		= $(SERVER_OBJ) $(CLIENT_OBJ)


all: comp_libft comp_server comp_client

#$(NAME): comp_libft comp_server comp_client

comp_libft:
	@ echo "libft compilation..."
	@ $(MAKE) -C $(LIBFT) all
	@ echo "libft compilation done..."

comp_server:
	@ echo "comp server..."
	@ $(CC) $(CFLAGS) -c $(SERVER_SRC)
	@ $(CC) -o $(SERVER) $(SERVER_OBJ) $(LIB)
	@ echo "comp server done..."

comp_client: $(CLIENT_SRC)
	@ echo "comp client..."
	@ $(CC) $(CFLAGS) -c $(CLIENT_SRC)
	@ $(CC) -o $(CLIENT) $(CLIENT_OBJ) $(LIB)
	@ echo "comp client done..."

clean:
	@ $(MAKE) -C $(LIBFT) clean
	@ rm -f $(OBJS)

fclean:
	@ rm -f $(SERVER) $(CLIENT)
	@ $(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all comp_libft comp_server comp_client clean fclean re