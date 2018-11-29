/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_on_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:07:48 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/29 17:00:10 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap_a_p(t_check *c)
{
	int		tmp;

	if (c->a < 1)
		return ;
	tmp = c->stack_a[c->a - 1];
	c->stack_a[c->a - 1] = c->stack_a[c->a];
	c->stack_a[c->a] = tmp;
	ft_dprintf(c->wfd, "sa\n");
}

void	ft_push_a_p(t_check *c)
{
	if (c->nb_b == 0)
		return ;
	c->a++;
	c->stack_a[c->a] = c->stack_b[c->b];
	c->stack_b[c->b] = 0;
	c->nb_a++;
	c->nb_b--;
	c->b--;
	ft_dprintf(c->wfd, "pa\n");
}

void	ft_rotate_a_p(t_check *c)
{
	int		tmp;
	int		i;

	if (c->nb_a == 0)
		return ;
	i = c->a;
	tmp = c->stack_a[c->a];
	while (i > 0)
	{
		c->stack_a[i] = c->stack_a[i - 1];
		i--;
	}
	c->stack_a[0] = tmp;
	ft_dprintf(c->wfd, "ra\n");
}

void	ft_reverse_rotate_a_p(t_check *c)
{
	int		tmp;
	int		i;

	if (c->nb_a == 0)
		return ;
	i = 0;
	tmp = c->stack_a[0];
	while (i + 1 < c->nb_a)
	{
		c->stack_a[i] = c->stack_a[i + 1];
		i++;
	}
	c->stack_a[c->a] = tmp;
	ft_dprintf(c->wfd, "rra\n");
}
