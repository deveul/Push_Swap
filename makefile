# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrenaudi <urenaudi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 14:25:25 by vrenaudi          #+#    #+#              #
#    Updated: 2018/11/28 16:43:42 by vrenaudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

NAME = checker

NAMEPS = push_swap

SRCSC = ./srcs_common/ft_check_format.c \
	   	./srcs_common/ft_check_format_str.c \
  		./srcs_common/ft_ope_on_a.c \
  		./srcs_common/ft_ope_on_a_p.c \
		./srcs_common/ft_ope_on_b.c \
		./srcs_common/ft_ope_on_b_p.c \
		./srcs_common/ft_ope_on_both.c \
		./srcs_common/ft_ope_on_both_p.c

SRCSCH = ./srcs_checker/main.c \

SRCSPS = ./srcs_push_swap/main.c \
		 ./srcs_push_swap/ft_sort_small.c \
		 ./srcs_push_swap/ft_sort_big.c \
		 ./srcs_push_swap/ft_calculate_value.c \
		 ./srcs_push_swap/ft_where_in_b.c \
		 ./srcs_push_swap/ft_do_and_print.c \
		 ./srcs_push_swap/ft_calc_diff_best.c \

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
