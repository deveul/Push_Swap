# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrenaudi <urenaudi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 14:25:25 by vrenaudi          #+#    #+#              #
#    Updated: 2018/11/26 11:16:01 by vrenaudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O2 -march=native -flto

NAME = checker

NAMEPS = push_swap

SRCSC = ./srcs_common/ft_check_format.c \
	   	./srcs_common/ft_check_format_str.c \
  		./srcs_common/ft_ope_on_a.c \
		./srcs_common/ft_ope_on_b.c \
		./srcs_common/ft_ope_on_both.c

SRCSCH = ./srcs_checker/main.c \

SRCSPS = ./srcs_push_swap/main.c \
		 ./srcs_push_swap/ft_sort_stack.c \
		 ./srcs_push_swap/ft_sort_stack2.c \
		 ./srcs_push_swap/ft_sort_stack3.c \

OBJC = $(SRCSC:.c=.o)

OBJCH = $(SRCSCH:.c=.o)

OBJPS = $(SRCSPS:.c=.o)

HEAD = -I ./srcs_checker/. -I ./srcs_push_swap/.

RM = rm -f

%.o: %.c
	$(CC) $(HEAD) $(CFLAGS) -o $@ -c $<

.PHONY: all
all: $(NAME)

$(NAME) : $(OBJC) $(OBJCH) $(OBJPS)
	Make -C ./libft
	$(CC) -o $(NAME) $(OBJC) $(OBJCH) $(CFLAGS) ./libft/libftprintf.a
	$(CC) -o $(NAMEPS) $(OBJC) $(OBJPS) $(CFLAGS) ./libft/libftprintf.a

.PHONY : clean
clean:
	Make clean -C ./libft
	$(RM) $(OBJC) $(OBJCH) $(OBJPS)

.PHONY : fclean
fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME) $(NAMEPS)

.PHONY : re
re:
	$(MAKE) fclean
	$(MAKE)
