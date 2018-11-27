/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:37:47 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/27 15:31:27 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_calc_diff_best(t_cbv *cbv)
{
	int		value;

	value = -1;
	if (cbv->besta == 1)
		value = cbv->ra + cbv->rrb;
	else if (cbv->besta == 2)
		value = cbv->rra + cbv->rb;
	return (value);
}

int			ft_calculate_value(t_cbv *cbv)
{
	int		value;

	value = -1;
	if (cbv->besta == cbv->bestb && cbv->besta == 1)
	{
		if (cbv->rb == cbv->ra)
			value = cbv->rb;
		else if (cbv->rb < cbv->ra)
			value = cbv->ra;
		else if (cbv->rb > cbv->ra)
			value = cbv->rb;
	}
	else if (cbv->besta == cbv->bestb && cbv->besta == 2)
	{
		if (cbv->rrb == cbv->rra)
			value = cbv->rrb;
		else if (cbv->rrb < cbv->rra)
			value = cbv->rra;
		else if (cbv->rrb > cbv->rra)
			value = cbv->rrb;
	}
	else if (cbv->besta != cbv->bestb)
		value = ft_calc_diff_best(cbv);
	return (value);
}
