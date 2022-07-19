# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 15:29:13 by yoav              #+#    #+#              #
#    Updated: 2022/07/19 13:06:59 by yoav             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = \
	input/percent_sign.c \
	input/parse_input.c \
	convert/itoa_base.c \
	convert/stoa_base.c \
	printable_mem/printable_mem.c \
	flag/flag.c \
	flag/parse_flag.c \
	flag/validate_flag.c \
	count/count_digit.c \
	generic/generic_unsigned_number.c \
	generic/generic.c \
	generic/generic_number.c \
	generic/zero_and_precision.c \
	ft_printf.c \
	print/print.c \
	handler/char.c \
	handler/hax_uppwer.c \
	handler/ptr.c \
	handler/str.c \
	handler/dec.c \
	handler/unsigned_dec.c \
	handler/hax_lower.c \
	list/list.c

HEADER_NAME = \
	base.h \
	convert.h \
	count.h \
	define.h \
	flag.h \
	ft_printf.h \
	generic.h \
	handler.h \
	input.h \
	list.h \
	print.h \
	printable_mem.h \

# TODO
BONUS_SRC = no.c

HEADER_DIR = include
HEADER = $(addprefix $(HEADER_DIR)/, $(HEADER_NAME))
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

# libft
LIBFT_NAME = libft.a
LIBFT_DIR = libft
LIBFT = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

CC = gcc
CFLAGS = -Wall -Werror -Wextra -c -I$(HEADER_DIR) -I$(LIBFT_DIR)
ARFLAGS = rcs

.PHONY: clean fclean re all bonus

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -o $@ 

all: $(NAME)

# $ ar r libarith.a subtraction.o 

# $ ar t libarith.a

$(LIBFT):
	$(MAKE) bonus -sC ./$(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT) $(HEADER)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(LIBFT) 

bonus: $(NAME) 

clean:
	$(MAKE) clean -sC $(LIBFT_DIR)
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(MAKE) fclean -sC $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all
