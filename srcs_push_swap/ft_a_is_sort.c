/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_is_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:50:35 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/29 16:58:51 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
