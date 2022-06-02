# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 13:38:25 by dduvivie          #+#    #+#              #
#    Updated: 2022/03/07 13:38:34 by dduvivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
LIBFT		= libft

CC			= gcc
CFLAGS 		= -Wall -Wextra -Werror

SRCS		= ft_printf.c \
			ft_print_char.c \
			ft_print_str.c \
			ft_print_int.c \
			ft_print_uint.c \
			ft_print_hex.c \
			ft_print_point.c \
			ft_convert.c \

OBJS		= $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	@ cp ../libft.a $(NAME)
	@ ar -rcs $(NAME) $(OBJS)
	@ mv $(NAME) ../libft.a
	
$(OBJS): $(SRCS)
	@ $(CC) $(CFLAGS) -c $(SRCS)

clean:
	@ rm -f $(OBJS)

fclean: clean
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
