# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 15:29:13 by yoav              #+#    #+#              #
#    Updated: 2022/06/15 15:34:58 by yoav             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = \
	ft_printf.c

BONUS_SRC = no.c

OBJ = $(SRC:.c=.o)
HED = include
BONUS_OBJ = $(BONUS_SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -c -I $(HED)
RM = rm -f

.PHONY: clean fclean re all bonus
.PRECIOUS: $(SRC) $(HED)

all: $(NAME)

$(NAME): $(OBJ) $(HED) Makefile 
	ar rcsv $(NAME) $(OBJ)

bonus: $(BONUS_OBJ) $(OBJ) $(HED) Makefile 
	ar rcsv $(NAME) $(OBJ) $(BONUS_OBJ)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
