# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrenaudi <urenaudi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 14:25:25 by vrenaudi          #+#    #+#              #
#    Updated: 2018/11/21 11:58:45 by vrenaudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

NAME = checker

SRCS = ./srcs_checker/main.c \
	   ./srcs_checker/ft_check_format.c \
	   ./srcs_checker/ft_ope_on_a.c \
	   ./srcs_checker/ft_ope_on_b.c \
	   ./srcs_checker/ft_ope_on_both.c \

OBJ = $(SRCS:.c=.o)

HEAD = -I ./

RM = rm -f

%.o: %.c
	$(CC) $(HEAD) $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME) : $(OBJ)
	Make -C ./libft
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) ./libft/libftprintf.a

clean:
	Make clean -C ./libft
	$(RM) $(OBJ)

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE)

.PHONY: clean, re, fclean
