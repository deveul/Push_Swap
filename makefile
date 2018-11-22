# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrenaudi <urenaudi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 14:25:25 by vrenaudi          #+#    #+#              #
#    Updated: 2018/11/21 16:26:21 by vrenaudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

NAME = checker

NAMEPS = push_swap

SRCSC = ./srcs_common/ft_check_format.c \
	   	./srcs_common/ft_check_format_str.c

SRCSCH = ./srcs_checker/main.c \
  		 ./srcs_checker/ft_ope_on_a.c \
		 ./srcs_checker/ft_ope_on_b.c \
		 ./srcs_checker/ft_ope_on_both.c \

SRCSPS = ./srcs_push_swap/main.c \

OBJC = $(SRCSC:.c=.o)

OBJCH = $(SRCSCH:.c=.o)

OBJPS = $(SRCSPS:.c=.o)

HEAD = -I ./srcs_checker/. -I ./srcs_push_swap/.

RM = rm -f

%.o: %.c
	$(CC) $(HEAD) $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME) : $(OBJC) $(OBJCH) $(OBJPS)
	Make -C ./libft
	$(CC) -o $(NAME) $(OBJC) $(OBJCH) $(CFLAGS) ./libft/libftprintf.a
	$(CC) -o $(NAMEPS) $(OBJC) $(OBJPS) $(CFLAGS) ./libft/libftprintf.a

clean:
	Make clean -C ./libft
	$(RM) $(OBJC) $(OBJCH) $(OBJPS)

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME) $(NAMEPS)

re:
	$(MAKE) fclean
	$(MAKE)

.PHONY: clean, re, fclean
