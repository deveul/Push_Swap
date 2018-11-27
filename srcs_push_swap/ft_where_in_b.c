/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_where_in_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:41:56 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/27 14:41:42 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_nb_is_surrounded(t_check *c, t_cbv *cbv, int nb)
{
	int		pos;

	pos = 0;
	if (c->stack_b[0] > nb && c->stack_b[c->b] < nb)
	{
		cbv->rb = 0;
		cbv->rrb = c->nb_b;
	}
	else
	{
		while (pos < c->nb_b)
		{
			if (pos != c->b && nb > c->stack_b[pos] && nb < c->stack_b[pos + 1])
			{
				cbv->rb = c->b - pos;
				cbv->rrb = pos + 1;
			}
			pos++;
		}
	}
}

void		ft_where_in_b(t_check *c, t_cbv *cbv, int i)
{
	int		nb;

	nb = c->stack_a[i];
	if (nb < cbv->minb)
	{
		cbv->rb = c->nb_b - cbv->posminb;
		cbv->rrb = cbv->posminb;
	}
	else if (nb > cbv->maxb)
	{
		cbv->rb = c->b - cbv->posmaxb;
		cbv->rrb = cbv->posmaxb + 1;
	}
	else
		ft_nb_is_surrounded(c, cbv, nb);
	if (cbv->rb > cbv->rrb)
		cbv->bestb = 2;
	else
		cbv->bestb = 1;
}
