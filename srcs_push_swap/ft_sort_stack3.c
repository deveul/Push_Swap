/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:54:35 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/27 17:23:14 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_finish_instructions(t_check *c, t_cbv *cbv, t_swap *s)
{
	while (c->stack_b[0] != cbv->minb)
	{
		ft_printf("rb\n");
		ft_rotate_b(c);
	}
	while (c->nb_b > 0)
	{
		ft_reverse_rotate_a(c);
		if (ft_a_is_sort(c, s) == 1)
			ft_printf("rra\n");
		else
			ft_rotate_a(c);
		ft_push_a(c);
		ft_printf("pa\n");
	}
	if (ft_a_is_sort(c, s) == -1)
		ft_reverse_rotate_a_p(c);
}

static void	ft_update_min_max(t_check *c, t_cbv *cbv)
{
	int		j;

	j = 0;
	cbv->minb = c->stack_b[0];
	cbv->posminb = 0;
	while (j < c->nb_b)
	{
		if (c->stack_b[j] < cbv->minb)
		{
			cbv->minb = c->stack_b[j];
			cbv->posminb = j;
		}
		j++;
	}
	j = 0;
	cbv->maxb = c->stack_b[0];
	cbv->posmaxb = 0;
	while (j < c->nb_b)
	{
		if (c->stack_b[j] > cbv->maxb)
		{
			cbv->maxb = c->stack_b[j];
			cbv->posmaxb = j;
		}
		j++;
	}
}

static void	ft_init_pile_b(t_check *c, t_cbv *cbv)
{
	ft_push_b(c);
	ft_push_b(c);
	ft_printf("pb\npb\n");
	if (c->stack_b[c->b] > c->stack_b[0])
	{
		cbv->minb = c->stack_b[0];
		cbv->posminb = 0;
		cbv->maxb = c->stack_b[1];
		cbv->posmaxb = 1;
	}
	else
	{
		cbv->maxb = c->stack_b[0];
		cbv->posmaxb = 0;
		cbv->minb = c->stack_b[1];
		cbv->posminb = 1;
	}
}

static void	ft_compare_values(t_cbv *cbv, int value, int *i)
{
	if (cbv->bestrb == -1 || value < cbv->bestvalue)
	{
		cbv->bestrb = cbv->rb;
		cbv->bestrrb = cbv->rrb;
		cbv->bestra = cbv->ra;
		cbv->bestrra = cbv->rra;
		cbv->bestbesta = cbv->besta;
		cbv->bestbestb = cbv->bestb;
		cbv->bestvalue = value;
	}
	(*i)--;
}

void		ft_sort_stack3(t_check *c, t_swap *s)
{
	int		i;
	int		value;
	t_cbv	cbv;

	ft_init_pile_b(c, &cbv);
	while (c->nb_a > 1)
	{
		i = c->a;
		cbv.bestrb = -1;
		while (i >= 0)
		{
			cbv.ra = c->a - i;
			cbv.rra = i + 1;
			if (cbv.ra > cbv.rra)
				cbv.besta = 2;
			else
				cbv.besta = 1;
			ft_where_in_b(c, &cbv, i);
			value = ft_calculate_value(&cbv);
			if (cbv.besta != cbv.bestb)
			{
				ft_printf("-----------------");
				ft_printf("value:%d\n", value);
				ft_printf("rb:%d\n", cbv.rb);
				ft_printf("rrb:%d\n", cbv.rrb);
				ft_printf("ra:%d\n", cbv.ra);
				ft_printf("rra:%d\n", cbv.rra);
			}
			ft_compare_values(&cbv, value, &i);
		}
		ft_print_instructions(c, &cbv);
		ft_update_min_max(c, &cbv);
	}
	ft_finish_instructions(c, &cbv, s);
}
