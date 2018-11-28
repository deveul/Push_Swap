/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:37:47 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/28 12:20:15 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_calc_diff_best(t_cbv *cbv)
{
	int		value;
	int		tmp1;
	int		tmp2;
	int		tmp3;

	value = -1;
	if (cbv->besta == 1)
		tmp1 = cbv->ra + cbv->rrb;
	else
		tmp1 = cbv->rra + cbv->rb;
	if (cbv->ra < cbv->rb)
		tmp2 = cbv->rb;
	else
		tmp2 = cbv->ra;
	if (cbv->rra < cbv->rrb)
		tmp3 = cbv->rrb;
	else
		tmp3 = cbv->rra;
	if (tmp1 <= tmp2 && tmp1 <= tmp3)
	{
		value = tmp1;
		if (cbv->besta == 1)
		{
			cbv->rra = 0;
			cbv->rb = 0;
		}
		else if (cbv->besta == 2)
		{
			cbv->ra = 0;
			cbv->rrb = 0;
		}
	}
	else if (tmp2 < tmp1 && tmp2 <= tmp3)
	{
		value = tmp2;
		cbv->rra = 0;
		cbv->rrb = 0;
		if (cbv->ra < cbv->rb)
		{
			cbv->rr = cbv->ra;
			cbv->rb -= cbv->rr;
			cbv->ra = 0;
		}
		else if (cbv->ra > cbv->rb)
		{
			cbv->rr = cbv->rb;
			cbv->ra -= cbv->rr;
			cbv->rb = 0;
		}
	}
	else if (tmp3 < tmp1 && tmp3 <= tmp2)
	{
		value = tmp3;
		cbv->ra = 0;
		cbv->rb = 0;
		if (cbv->rra < cbv->rrb)
		{
			cbv->rrr = cbv->rra;
			cbv->rrb -= cbv->rrr;
			cbv->rra = 0;
		}
		else if (cbv->rra > cbv->rrb)
		{
			cbv->rrr = cbv->rrb;
			cbv->rra -= cbv->rrr;
			cbv->rrb = 0;
		}
	}
	return (value);
}

int			ft_calculate_value(t_cbv *cbv)
{
	int		value;

	value = -1;
	cbv->rr = 0;
	cbv->rrr = 0;
	if (cbv->besta == cbv->bestb && cbv->besta == 1)
	{
		cbv->rrb = 0;
		cbv->rra = 0;
		if (cbv->rb == cbv->ra)
		{
			value = cbv->rb;
			cbv->rr = cbv->rb;
			cbv->rb = 0;
			cbv->ra = 0;
		}
		else if (cbv->rb < cbv->ra)
		{
			value = cbv->ra;
			cbv->rr = cbv->rb;
			cbv->ra -= cbv->rr;
			cbv->rb = 0;
		}
		else if (cbv->rb > cbv->ra)
		{
			value = cbv->rb;
			cbv->rr = cbv->ra;
			cbv->rb -= cbv->rr;
			cbv->ra = 0;
		}
	}
	else if (cbv->besta == cbv->bestb && cbv->besta == 2)
	{
		cbv->rb = 0;
		cbv->ra = 0;
		if (cbv->rrb == cbv->rra)
		{
			value = cbv->rrb;
			cbv->rrr = cbv->rrb;
			cbv->rrb = 0;
			cbv->rra = 0;
		}
		else if (cbv->rrb < cbv->rra)
		{
			value = cbv->rra;
			cbv->rrr = cbv->rrb;
			cbv->rra -= cbv->rrr;
			cbv->rrb = 0;
		}
		else if (cbv->rrb > cbv->rra)
		{
			value = cbv->rrb;
			cbv->rrr = cbv->rra;
			cbv->rrb -= cbv->rrr;
			cbv->rra = 0;
		}
	}
	else if (cbv->besta != cbv->bestb)
		value = ft_calc_diff_best(cbv);
	return (value);
}
