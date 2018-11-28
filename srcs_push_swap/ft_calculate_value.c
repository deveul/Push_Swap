/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:37:47 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/28 13:30:19 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_calculate_same_best_one(t_cbv *cbv, int *value)
{
	cbv->rrb = 0;
	cbv->rra = 0;
	if (cbv->rb == cbv->ra)
	{
		(*value) = cbv->rb;
		cbv->rr = cbv->rb;
		cbv->rb = 0;
		cbv->ra = 0;
	}
	else if (cbv->rb < cbv->ra)
	{
		(*value) = cbv->ra;
		cbv->rr = cbv->rb;
		cbv->ra -= cbv->rr;
		cbv->rb = 0;
	}
	else
	{
		(*value) = cbv->rb;
		cbv->rr = cbv->ra;
		cbv->rb -= cbv->rr;
		cbv->ra = 0;
	}
}

static void	ft_calculate_same_best_two(t_cbv *cbv, int *value)
{
	cbv->rb = 0;
	cbv->ra = 0;
	if (cbv->rrb == cbv->rra)
	{
		(*value) = cbv->rrb;
		cbv->rrr = cbv->rrb;
		cbv->rrb = 0;
		cbv->rra = 0;
	}
	else if (cbv->rrb < cbv->rra)
	{
		(*value) = cbv->rra;
		cbv->rrr = cbv->rrb;
		cbv->rra -= cbv->rrr;
		cbv->rrb = 0;
	}
	else
	{
		(*value) = cbv->rrb;
		cbv->rrr = cbv->rra;
		cbv->rrb -= cbv->rrr;
		cbv->rra = 0;
	}
}

int			ft_calculate_value(t_cbv *cbv)
{
	int		value;

	value = -1;
	cbv->rr = 0;
	cbv->rrr = 0;
	if (cbv->besta == cbv->bestb && cbv->besta == 1)
		ft_calculate_same_best_one(cbv, &value);
	else if (cbv->besta == cbv->bestb && cbv->besta == 2)
		ft_calculate_same_best_two(cbv, &value);
	else if (cbv->besta != cbv->bestb)
		ft_calc_diff_best(cbv, &value);
	return (value);
}
