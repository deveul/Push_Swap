/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:54:35 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/29 16:59:34 by vrenaudi         ###   ########.fr       */
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

static int	ft_a_is_sort_circular(t_check *c, t_swap *s)
{
	int		i;
	int		start;

	i = -1;
	start = 0;
	ft_swap_a(c);
	while (++i < c->nb)
		if (s->sort[i] == c->stack_a[0])
		{
			start = i;
			break ;
		}
	i = -1;
	while (++i < c->nb_a)
	{
		if (start == c->nb)
			start = 0;
		if (c->stack_a[i] != s->sort[start++])
		{
			ft_swap_a(c);
			return (-1);
		}
	}
	ft_dprintf(c->wfd, "sa\n");
	return (1);
}

static int	ft_sort_if_swap(t_check *c, t_swap *s)
{
	ft_swap_a(c);
	if (ft_a_is_sort(c, s) == 1)
	{
		ft_dprintf(c->wfd, "sa\n");
		return (1);
	}
	ft_swap_a(c);
	return (-1);
}

static void	ft_pos_below_middle(t_check *c, int pos)
{
	while (pos > 1)
	{
		ft_rotate_a_p(c);
		pos--;
	}
	if (pos > 0 && c->stack_a[c->a] > c->stack_a[0])
		ft_rotate_a_p(c);
	else if (pos > 0)
		ft_swap_a_p(c);
}

void		ft_sort_small(t_check *c, t_swap *s)
{
	int		i;
	int		pos;
	int		middle_a;

	i = 0;
	pos = 0;
	while (ft_a_is_sort(c, s) == -1)
	{
		if (ft_sort_if_swap(c, s) == 1)
			break ;
		ft_a_is_sort_circular(c, s);
		pos = ft_locate_int(c, s, i);
		middle_a = c->nb_a / 2;
		if (pos <= middle_a)
			ft_pos_below_middle(c, pos);
		else
			while (pos++ < c->nb_a)
				ft_reverse_rotate_a_p(c);
		if (ft_a_is_sort(c, s) == -1)
			ft_push_b_p(c);
		i++;
	}
	while (c->nb_b > 0)
		ft_push_a_p(c);
}
