# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mebourge <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 17:12:04 by mebourge          #+#    #+#              #
#    Updated: 2022/10/19 14:21:04 by mebourge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
	ft_printf_utils.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Werror -Wextra

LIB = ar rcs $(NAME)

REMOVE = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@$(LIB) $(OBJ)
clean:
	@$(REMOVE) $(OBJ)

fclean: clean
	@$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re
