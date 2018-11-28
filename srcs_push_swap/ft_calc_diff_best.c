/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_diff_best.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:29:18 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/28 13:40:50 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_tmp1_is_better(t_cbv *cbv, int *value, int tmp1)
{
	(*value) = tmp1;
	if (cbv->besta == 1)
	{
		cbv->rra = 0;
		cbv->rb = 0;
	}
	else
	{
		cbv->ra = 0;
		cbv->rrb = 0;
	}
}

static void	ft_tmp2_is_better(t_cbv *cbv, int *value, int tmp2)
{
	(*value) = tmp2;
	cbv->rra = 0;
	cbv->rrb = 0;
	if (cbv->ra < cbv->rb)
	{
		cbv->rr = cbv->ra;
		cbv->rb -= cbv->rr;
		cbv->ra = 0;
	}
	else
	{
		cbv->rr = cbv->rb;
		cbv->ra -= cbv->rr;
		cbv->rb = 0;
	}
}

static void	ft_tmp3_is_better(t_cbv *cbv, int *value, int tmp3)
{
	(*value) = tmp3;
	cbv->ra = 0;
	cbv->rb = 0;
	if (cbv->rra < cbv->rrb)
	{
		cbv->rrr = cbv->rra;
		cbv->rrb -= cbv->rrr;
		cbv->rra = 0;
	}
	else
	{
		cbv->rrr = cbv->rrb;
		cbv->rra -= cbv->rrr;
		cbv->rrb = 0;
	}
}

void		ft_calc_diff_best(t_cbv *cbv, int *value)
{
	int		tmp1;
	int		tmp2;
	int		tmp3;

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
		ft_tmp1_is_better(cbv, value, tmp1);
	else if (tmp2 <= tmp1 && tmp2 <= tmp3)
		ft_tmp2_is_better(cbv, value, tmp2);
	else
		ft_tmp3_is_better(cbv, value, tmp3);
}
