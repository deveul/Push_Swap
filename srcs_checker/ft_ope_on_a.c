/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_on_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:07:48 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/21 11:12:50 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap_a(t_check *c)
{
	int		tmp;

	if (c->a < 1)
		return ;
	tmp = c->pile_a[c->a - 1];
	c->pile_a[c->a - 1] = c->pile_a[c->a];
	c->pile_a[c->a] = tmp;
}

void	ft_push_a(t_check *c)
{
	if (c->nb_b == 0)
		return ;
	c->a++;
	c->pile_a[c->a] = c->pile_b[c->b];
	c->pile_b[c->b] = -1000;
	c->nb_a++;
	c->nb_b--;
	c->b--;
}

void ft_rotate_a(t_check *c)
{
	int		tmp;
	int		i;

	if (c->nb_a == 0)
		return ;
	i = c->a;
	tmp = c->pile_a[c->a];
	while (i > 0)
	{
		c->pile_a[i] = c->pile_a[i - 1];
		i--;
	}
	c->pile_a[0] = tmp;
}

void ft_reverse_rotate_a(t_check *c)
{
	int		tmp;
	int		i;

	if (c->nb_a == 0)
		return ;
	i = 0;
	tmp = c->pile_a[0];
	while (i + 1 < c->nb_a)
	{
		c->pile_a[i] = c->pile_a[i + 1];
		i++;
	}
	c->pile_a[c->a] = tmp;
}