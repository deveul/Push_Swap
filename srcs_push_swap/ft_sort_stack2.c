/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:54:35 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/27 16:55:39 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_locate_int(t_check *c, t_swap *s, int pos)
{
	int		i;
	int		j;

	i = c->a;
	j = 0;
	while (c->stack_a[i] != s->revsort[pos])
	{
		i--;
		j++;
	}
	return (j);
}

int			ft_a_is_sort(t_check *c, t_swap *s)
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

void		ft_sort_stack2(t_check *c, t_swap *s)
{
	int		i;
	int		j;
	int		pos;
	int		middle_a;

	i = 0;
	pos = 0;
	while (ft_a_is_sort(c, s) == -1 && c->nb_b != c->nb)
	{
		ft_swap_a(c);
		if (ft_a_is_sort(c, s) == 1)
		{
			ft_printf("sa\n");
			break ;
		}
		ft_swap_a(c);
		pos = ft_locate_int(c, s, i);
		if (c->nb_a % 2 == 0)
			middle_a = c->nb_a / 2;
		else
			middle_a = c->nb_a / 2 + 1;
		j = 0;
		if (pos <= middle_a)
		{
			while (pos > 1)
			{
				ft_rotate_a(c);
				ft_printf("ra\n");
				pos--;
			}
			if (pos > 0 && c->stack_a[c->a] > c->stack_a[0])
			{
				ft_rotate_a(c);
				ft_printf("ra\n");
			}
			else if (pos > 0)
			{
				ft_swap_a(c);
				ft_printf("sa\n");
			}
		}
		else if (pos != 0)
		{
			while (pos < c->nb_a)
			{
				ft_reverse_rotate_a(c);
				ft_printf("rra\n");
				pos++;
			}
		}
		if (ft_a_is_sort(c, s) == -1)
		{
			ft_push_b(c);
			ft_printf("pb\n");
		}
		i++;
	}
	while (c->nb_b > 0)
	{
		ft_push_a(c);
		ft_printf("pa\n");
	}
}
