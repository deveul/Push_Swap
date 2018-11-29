/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:26:49 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/29 11:51:24 by vrenaudi         ###   ########.fr       */
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
	int			bestra;
	int			bestrb;
	int			bestrr;
	int			bestrra;
	int			bestrrb;
	int			bestrrr;
	int			besta;
	int			bestb;
	int			bestbesta;
	int			bestvalue;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
	int			minb;
	int			maxb;
	int			posminb;
	int			posmaxb;
}				t_cbv;

void			ft_sort_small(t_check *c, t_swap *s);
void			ft_sort_big(t_check *c, t_swap *s);
int				ft_calculate_value(t_cbv *cbv);
void			ft_calc_diff_best(t_cbv *cbv, int *value);
void			ft_where_in_b(t_check *c, t_cbv *cbv, int i);
void			ft_do_and_print(t_check *c, t_cbv *cbv);
int				ft_a_is_sort(t_check *c, t_swap *s);

#endif
