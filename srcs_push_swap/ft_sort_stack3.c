/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:54:35 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/26 18:06:04 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_a_is_sort(t_check *c, t_swap *s)
{
	int		i;

	i = 0;
	while (i < c->nb_a)
	{
		if (c->stack_a[i] != s->sort[i])
			return (-1);
		i++;
	}
	return (1);
}

static void	ft_where_in_b(t_check *c, t_cbv *cbv, int i)
{
	int		pos;
	int		nb;
	int		j;

	nb = c->stack_a[i];
//	ft_printf("nb = %d\n", nb);
	j = 0;
	while (j < c->nb_b)
	{
//		ft_printf("%4d", c->stack_b[j]);
		j++;
	}
//	ft_putendl("");
//	ft_printf("posbmin:%d\n", cbv->posminb);
//	ft_printf("minb:%d\n", cbv->minb);
	pos = 0;
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
	{
		if (c->stack_b[0] > nb && c->stack_b[c->b] < nb)
		{
			cbv->rb = 0;
			cbv->rrb = c->nb_b;
		}
		while (pos < c->nb_b)
		{
			if (pos != c->b && nb > c->stack_b[pos] && nb < c->stack_b[pos + 1])
			{
//				ft_printf("pos:%d\n", pos);
				cbv->rb = c->b - pos;
				cbv->rrb = pos + 1;
			}
			pos++;
		}
	}
	if (cbv->rb > cbv->rrb)
		cbv->bestb = 2;
	else
		cbv->bestb = 1;
}

static void	ft_print_instructions(t_check *c, t_cbv *cbv)
{
	int		i;

	i = 0;
	if (cbv->bestbesta == cbv->bestbestb && cbv->bestbesta == 1)
	{
		if (cbv->bestrb == cbv->bestra)
		{
			while (i < cbv->bestrb)
			{
				ft_rotate_both(c);
				ft_printf("rr\n");
				i++;
			}
		}
		else if (cbv->bestrb < cbv->bestra)
		{
			while (i < cbv->bestrb)
			{
				ft_rotate_both(c);
				ft_printf("rr\n");
				i++;
			}
			while (i < cbv->bestra)
			{
				ft_rotate_a(c);
				ft_printf("ra\n");
				i++;
			}
		}
		else if (cbv->bestrb > cbv->bestra)
		{
			while (i < cbv->bestra)
			{
				ft_rotate_both(c);
				ft_printf("rr\n");
				i++;
			}
			while (i < cbv->bestrb)
			{
				ft_rotate_b(c);
				ft_printf("rb\n");
				i++;
			}
		}
	}
	else if (cbv->bestbesta == cbv->bestbestb && cbv->bestbesta == 2)
	{
		if (cbv->bestrrb == cbv->bestrra)
		{
			while (i < cbv->bestrrb)
			{
				ft_reverse_rotate_both(c);
				ft_printf("rrr\n");
				i++;
			}
		}
		else if (cbv->bestrrb < cbv->bestrra)
		{
			while (i < cbv->bestrrb)
			{
				ft_reverse_rotate_both(c);
				ft_printf("rrr\n");
				i++;
			}
			while (i < cbv->bestrra)
			{
				ft_reverse_rotate_a(c);
				ft_printf("rra\n");
				i++;
			}
		}
		else if (cbv->bestrrb > cbv->bestrra)
		{
			while (i < cbv->bestrra)
			{
				ft_reverse_rotate_both(c);
				ft_printf("rrr\n");
				i++;
			}
			while (i < cbv->bestrrb)
			{
				ft_reverse_rotate_b(c);
				ft_printf("rrb\n");
				i++;
			}
		}
	}
	else if (cbv->bestbesta != cbv->bestbestb)
	{
		if (cbv->bestbesta == 1)
		{
			while (i < cbv->bestra)
			{
				ft_rotate_a(c);
				ft_printf("ra\n");
				i++;
			}
			while (i < cbv->bestvalue)
			{
				ft_reverse_rotate_b(c);
				ft_printf("rrb\n");
				i++;
			}
		}
		else if (cbv->bestbesta == 2)
		{
			while (i < cbv->bestrra)
			{
				ft_reverse_rotate_a(c);
				ft_printf("rra\n");
				i++;
			}
			while (i < cbv->bestvalue)
			{
				ft_rotate_b(c);
				ft_printf("rb\n");
				i++;
			}
		}
	}
	ft_push_b(c);
	ft_printf("pb\n");
}


static int	ft_calculate_value(t_cbv *cbv)
{
	int		value;

	value = -1;
	if (cbv->besta == cbv->bestb && cbv->besta == 1)
	{
		if (cbv->rb == cbv->ra)
			value = cbv->rb;
		else if (cbv->rb < cbv->ra)
			value = cbv->rb + (cbv->ra - cbv->rb);
		else if (cbv->rb > cbv->ra)
			value = cbv->ra + (cbv->rb - cbv->ra);
	}
	else if (cbv->besta == cbv->bestb && cbv->besta == 2)
	{
		if (cbv->rrb == cbv->rra)
			value = cbv->rrb;
		else if (cbv->rrb < cbv->rra)
			value = cbv->rrb + (cbv->rra - cbv->rrb);
		else if (cbv->rrb > cbv->rra)
			value = cbv->rra + (cbv->rrb - cbv->rra);
	}
	else if (cbv->besta != cbv->bestb)
	{
		if (cbv->besta == 1)
			value = cbv->ra + cbv->rrb;
		else if (cbv->besta == 2)
			value = cbv->rra + cbv->rb;
	}
	return (value);
}

void		ft_sort_stack3(t_check *c, t_swap *s)
{
	int		i;
	int		j;
	int		value;
	t_cbv	cbv;

	cbv.bestrb = -1;
	ft_push_b(c);
	ft_push_b(c);
	ft_printf("pb\npb\n");
	if (ft_a_is_sort(c, s) == 1)
		ft_printf("useless");
	if (c->stack_b[c->b] > c->stack_b[0])
	{
		cbv.minb = c->stack_b[0];
		cbv.posminb = 0;
		cbv.maxb = c->stack_b[1];
		cbv.posmaxb = 1;
	}
	else
	{
		cbv.maxb = c->stack_b[0];
		cbv.posmaxb = 0;
		cbv.minb = c->stack_b[1];
		cbv.posminb = 1;
	}
	while (c->nb_a > 0)
	{
		i = c->a;
		cbv.bestrb = -1;
		while (i >= 0)
		{
//			ft_printf("i est : %d\n", i);
			cbv.ra = c->a - i;
			cbv.rra	= i + 1;
			if (cbv.ra > cbv.rra)
				cbv.besta = 2;
			else
				cbv.besta = 1;
			ft_where_in_b(c, &cbv, i);
			if (cbv.bestrb == -1)
			{
/*				ft_printf("--------------\n");
				ft_printf("cbv.firstra = %d\n", cbv.ra);
				ft_printf("cbv.firstrb = %d\n", cbv.rb);
				ft_printf("cbv.firstrra = %d\n", cbv.rra);
				ft_printf("cbv.firstrrb = %d\n", cbv.rrb);
*/				cbv.bestrb = cbv.rb;
				cbv.bestrrb = cbv.rrb;
				cbv.bestra = cbv.ra;
				cbv.bestrra = cbv.rra;
				cbv.bestbesta = cbv.besta;
				cbv.bestbestb = cbv.bestb;
				cbv.bestvalue = ft_calculate_value(&cbv);
			}
			else
			{
				value = ft_calculate_value(&cbv);
				if (value < cbv.bestvalue)
				{
//					ft_printf("change value with i = %d\n", i);
					cbv.bestrb = cbv.rb;
					cbv.bestrrb = cbv.rrb;
					cbv.bestra = cbv.ra;
					cbv.bestrra = cbv.rra;
/*					ft_printf("--------------\n");
					ft_printf("cbv.firstra = %d\n", cbv.ra);
					ft_printf("cbv.firstrb = %d\n", cbv.rb);
					ft_printf("cbv.firstrra = %d\n", cbv.rra);
					ft_printf("cbv.firstrrb = %d\n", cbv.rrb);
*/					cbv.bestbesta = cbv.besta;
					cbv.bestbestb = cbv.bestb;
					cbv.bestvalue = value;
				}
			}
			i--;
		}
/*		ft_printf("--------------\n");
		ft_printf("cbv.bestra = %d\n", cbv.bestra);
		ft_printf("cbv.bestrb = %d\n", cbv.bestrb);
		ft_printf("cbv.bestrra = %d\n", cbv.bestrra);
		ft_printf("cbv.bestrrb = %d\n", cbv.bestrrb);
*/		ft_print_instructions(c, &cbv);
//		ft_printf("nouveau coup\n");
		j = 0;
		cbv.minb = c->stack_b[0];
		while (j < c->nb_b)
		{
			if (c->stack_b[j] < cbv.minb)
			{
				cbv.minb = c->stack_b[j];
				cbv.posminb = j;
			}
			j++;
		}
		j = 0;
		cbv.maxb = c->stack_b[0];
		while (j < c->nb_b)
		{
			if (c->stack_b[j] > cbv.maxb)
			{
				cbv.maxb = c->stack_b[j];
				cbv.posmaxb = j;
			}
			j++;
		}
	}
	while (c->stack_b[0] != cbv.minb)
	{
		ft_printf("rb\n");
		ft_rotate_b(c);
	}
	while (c->nb_b > 0)
	{
		ft_push_a(c);
		ft_printf("pa\n");
	}
}
