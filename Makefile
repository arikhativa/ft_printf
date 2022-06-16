# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 15:29:13 by yoav              #+#    #+#              #
#    Updated: 2022/06/16 14:40:51 by yoav             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = \
	ft_printf.c

BONUS_SRC = no.c

OBJ = $(SRC:.c=.o)
HED = include/*.h ./$(LIBFT)/$(LIBFT).h
BONUS_OBJ = $(BONUS_SRC:.c=.o)
LIBFT = libft

CC = gcc
CFLAGS = -Wall -Werror -Wextra -c -I $(HED)
RM = rm -f
AR = ar -rcs

.PHONY: clean fclean re all bonus
.PRECIOUS: $(SRC) $(HED) $(LIBFT)

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
