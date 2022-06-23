# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 15:29:13 by yoav              #+#    #+#              #
#    Updated: 2022/06/23 16:49:25 by yoav             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = \
	$(wildcard handler/*.c) \
	$(wildcard list/*.c) \
	$(wildcard convert/*.c) \
	$(wildcard input/*.c) \
	$(wildcard generic/*.c) \
	$(wildcard print/*.c) \
	$(wildcard flag/*.c) \
	$(wildcard count/*.c) \
	$(wildcard printable_mem/*.c) \
	ft_printf.c

BONUS_SRC = no.c

OBJ = $(SRC:.c=.o)
HED = include
BONUS_OBJ = $(BONUS_SRC:.c=.o)
LIBFT = libft

CC = gcc
CFLAGS = -Wall -Werror -Wextra -c -I$(HED) -Ilibft
RM = rm -f
AR = ar -rcs

.PHONY: clean fclean re all bonus
.PRECIOUS: $(SRC) $(HED) $(LIBFT)

all: $(NAME)

t: all
	gcc -Iinclude test.c $(NAME)

$(NAME): $(OBJ) $(HED) Makefile
	$(MAKE) bonus -C ./$(LIBFT)
	cp $(LIBFT)/libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

bonus: $(NAME) 

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all
