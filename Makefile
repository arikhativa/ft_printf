# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 15:29:13 by yoav              #+#    #+#              #
#    Updated: 2022/06/19 12:35:14 by yoav             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = \
	$(wildcard list/*.c) \
	$(wildcard converter/*.c) \
	$(wildcard parser/*.c) \
	$(wildcard printer/*.c) \
	ft_printf.c

BONUS_SRC = no.c

OBJ = $(SRC:.c=.o)
HED = include
BONUS_OBJ = $(BONUS_SRC:.c=.o)
LIBFT = libft

CC = gcc
CFLAGS = -c -I$(HED) -Ilibft
# CFLAGS = -Wall -Werror -Wextra -c -I$(HED) -Ilibft
RM = rm -f
AR = ar -rcs

.PHONY: clean fclean re all bonus
.PRECIOUS: $(SRC) $(HED) $(LIBFT)

t: all
	gcc -Iinclude test.c $(NAME)

all: $(NAME)

$(NAME): $(OBJ) $(HED) Makefile
	$(MAKE) bonus -C ./$(LIBFT)
	cp $(LIBFT)/libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

bonus: $(BONUS_OBJ) $(OBJ) $(HED) Makefile 
	$(AR) $(NAME) $(OBJ) $(BONUS_OBJ)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all
