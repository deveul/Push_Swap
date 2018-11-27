/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:26:49 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/27 13:58:36 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/printf/ft_printf.h"
# include "../libft/libft/get_next_line.h"
# include "../srcs_checker/checker.h"

typedef struct	s_swap
{
	int			*sort;
	int			*revsort;
}				t_swap;

typedef struct	s_cbv
{
	int			bestrb;
	int			bestrrb;
	int			bestra;
	int			bestrra;
	int			ra;
	int			rra;
	int			besta;
	int			bestbesta;
	int			rb;
	int			rrb;
	int			bestb;
	int			bestbestb;
	int			bestvalue;
	int			minb;
	int			posminb;
	int			maxb;
	int			posmaxb;
}				t_cbv;

void			ft_sort_stack2(t_check *c, t_swap *s);
void			ft_sort_stack3(t_check *c);
int				ft_calculate_value(t_cbv *cbv);
void			ft_where_in_b(t_check *c, t_cbv *cbv, int i);
void			ft_print_instructions(t_check *c, t_cbv *cbv);

#endif
