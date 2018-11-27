/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:42:52 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/27 17:23:15 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_equal_one(t_check *c, t_cbv *cbv, int i)
{
	if (cbv->bestrb == cbv->bestra)
		while (i++ < cbv->bestrb)
			ft_rotate_both_p(c);
	else if (cbv->bestrb < cbv->bestra)
	{
		while (i < cbv->bestrb)
		{
			ft_rotate_both_p(c);
			i++;
		}
		while (i++ < cbv->bestra)
			ft_rotate_a_p(c);
	}
	else if (cbv->bestrb > cbv->bestra)
	{
		while (i < cbv->bestra)
		{
			ft_rotate_both_p(c);
			i++;
		}
		while (i++ < cbv->bestrb)
			ft_rotate_b_p(c);
	}
}

static void	ft_print_equal_two(t_check *c, t_cbv *cbv, int i)
{
	if (cbv->bestrrb == cbv->bestrra)
		while (i++ < cbv->bestrrb)
			ft_reverse_rotate_both_p(c);
	else if (cbv->bestrrb < cbv->bestrra)
	{
		while (i < cbv->bestrrb)
		{
			ft_reverse_rotate_both_p(c);
			i++;
		}
		while (i++ < cbv->bestrra)
			ft_reverse_rotate_a_p(c);
	}
	else if (cbv->bestrrb > cbv->bestrra)
	{
		while (i < cbv->bestrra)
		{
			ft_reverse_rotate_both_p(c);
			i++;
		}
		while (i++ < cbv->bestrrb)
			ft_reverse_rotate_b_p(c);
	}
}

static void	ft_print_diff_one(t_check *c, t_cbv *cbv)
{
	int		i;

	i = 0;
	if (cbv->bestra + cbv->bestrrb < cbv->bestrb)
	{
		while (i < cbv->bestra)
		{
			ft_rotate_a_p(c);
			i++;
		}
		while (i < cbv->bestvalue)
		{
			ft_reverse_rotate_b_p(c);
			i++;
		}
	}
	else
	{
		while (i < cbv->bestra)
		{
			ft_rotate_both_p(c);
			i++;
		}
		while (i < cbv->bestrb)
		{
			ft_rotate_b_p(c);
			i++;
		}
	}
}

static void	ft_print_diff_two(t_check *c, t_cbv *cbv)
{
	int		i;

	i = 0;
	if (cbv->bestrra + cbv->bestrb < cbv->bestrrb)
	{
		while (i < cbv->bestrra)
		{
			ft_reverse_rotate_a_p(c);
			i++;
		}
		while (i < cbv->bestvalue)
		{
			ft_rotate_b_p(c);
			i++;
		}
	}
	else
	{
		while (i < cbv->bestrra)
		{
			ft_reverse_rotate_both_p(c);
			i++;
		}
		while (i < cbv->bestrrb)
		{
			ft_rotate_b_p(c);
			i++;
		}
	}
}

void		ft_print_instructions(t_check *c, t_cbv *cbv)
{
	int		i;

	i = 0;
	if (cbv->bestbesta == cbv->bestbestb && cbv->bestbesta == 1)
		ft_print_equal_one(c, cbv, i);
	else if (cbv->bestbesta == cbv->bestbestb && cbv->bestbesta == 2)
		ft_print_equal_two(c, cbv, i);
	else if (cbv->bestbesta != cbv->bestbestb)
	{
		if (cbv->bestbesta == 1)
			ft_print_diff_one(c, cbv);
		else if (cbv->bestbesta == 2)
			ft_print_diff_two(c, cbv);
	}
	ft_push_b_p(c);
}
