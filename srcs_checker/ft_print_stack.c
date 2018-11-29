/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:10:56 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/29 16:54:54 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_slower(t_check *c)
{
	int		i;

	i = 0;
	if (c->option_s == 0)
		return ;
	else if (c->option_s == 1)
	{
		while (i < 10000000)
			i++;
	}
	else if (c->option_s == 2)
	{
		while (i < 100000000)
			i++;
	}
	else
	{
		while (i < 1000000000)
			i++;
	}
}

void		ft_print_stack(t_check *c, char *line)
{
	int		i;
	int		j;

	if (c->optionv == 0)
		return ;
	i = 0;
	j = c->nb - 1;
	ft_dprintf(c->wfd, "instruction played : %s\n", line);
	ft_dprintf(c->wfd, "nb_a : %d		nb_b : %d\n", c->nb_a, c->nb_b);
	ft_dprintf(c->wfd, "stack a:		stack b:\n", 0);
	while (++i < (c->nb + 1))
	{
		if (j < c->nb_a)
			ft_dprintf(c->wfd, "%8d", c->stack_a[j]);
		else
			ft_dprintf(c->wfd, "%8.d", 0);
		if (j < c->nb_b)
			ft_dprintf(c->wfd, "		%8d", c->stack_b[j]);
		else
			ft_dprintf(c->wfd, "		%.d", 0);
		ft_dprintf(c->wfd, "\n");
		j--;
	}
	ft_dprintf(c->wfd, "nombre de coup joue : %d\n\n", c->nb_played++);
	ft_slower(c);
}
