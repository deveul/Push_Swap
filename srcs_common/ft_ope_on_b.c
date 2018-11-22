/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_on_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:11:28 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/22 18:07:46 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs_checker/checker.h"

void	ft_swap_b(t_check *c)
{
	int		tmp;

	if (c->b < 1)
		return ;
	tmp = c->stack_b[c->b - 1];
	c->stack_b[c->b - 1] = c->stack_b[c->b];
	c->stack_b[c->b] = tmp;
}

void	ft_push_b(t_check *c)
{
	if (c->nb_a == 0)
		return ;
	c->b++;
	c->stack_b[c->b] = c->stack_a[c->a];
	c->stack_a[c->a] = 0;
	c->nb_a--;
	c->a--;
	c->nb_b++;
}

void	ft_rotate_b(t_check *c)
{
	int		tmp;
	int		i;

	if (c->nb_b == 0)
		return ;
	i = c->b;
	tmp = c->stack_b[c->b];
	while (i > 0)
	{
		c->stack_b[i] = c->stack_b[i - 1];
		i--;
	}
	c->stack_b[0] = tmp;
}

void	ft_reverse_rotate_b(t_check *c)
{
	int		tmp;
	int		i;

	if (c->nb_b == 0)
		return ;
	i = 0;
	tmp = c->stack_b[0];
	while (i + 1 < c->nb_b)
	{
		c->stack_b[i] = c->stack_b[i + 1];
		i++;
	}
	c->stack_b[c->b] = tmp;
}
