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

SERVER		= server.c
CLIENT		= client.c
LIB			= libft
LIBFT		= libft/libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCLUDE		= -I./include

SERVER_SRC	= $(SERVER)
SERVER_OBJ	= $(SERVER_SRC:.c=.o)	
CLIENT_SRC	= $(CLIENT) 
CLIENT_OBJ	= $(CLIENT_SRC:.c=.o)
OBJS		= $(SERVER_OBJ), $(CLIENT_OBJ)

NAME		= server

all: $(NAME)

$(NAME): comp_libft comp_server comp_client

comp_libft:
	@make -C $(LIB)
	@cp  .
	@mv libft.a $(NAME)

comp_server: $(SERVER_OBJ)
	@$(CC) $(CFLAGS) $(SERVER_OBJ) 