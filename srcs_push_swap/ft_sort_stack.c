/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:54:35 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/26 11:13:33 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_sort_stack(t_check *c, t_swap *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (c->stack_a[j] != s->sort[i])
		j++;
	while (c->stack_a[i] != s->sort[i])
	{
		if (j < (c->nb / 2))
		{
			ft_reverse_rotate_a(c);
			ft_printf("rra\n");
		}
		else
		{
			ft_rotate_a(c);
			ft_printf("ra\n");
		}
	}
	i++;
	while (c->nb_a > i)
	{
		ft_push_b(c);
		ft_printf("pb\n");
	}
	while (i < (c->nb - 1))
	{
		j = 0;
		while (c->stack_b[j] != s->sort[i])
			j++;
		if (j < (c->nb_b / 2))
		{
			while (c->stack_b[c->b] != s->sort[i])
			{
				ft_reverse_rotate_b(c);
				ft_printf("rrb\n");
			}
			ft_push_a(c);
			ft_printf("pa\n");
			i++;
		}
		else
		{
			while (c->stack_b[c->b] != s->sort[i])
			{
				ft_rotate_b(c);
				ft_printf("rb\n");
			}
			ft_push_a(c);
			ft_printf("pa\n");
			i++;
		}

	}
	ft_push_a(c);
	ft_printf("pa\n");
}
