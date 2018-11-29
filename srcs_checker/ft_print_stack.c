/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:10:56 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/29 15:12:39 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_print_stack(t_check *c, char *line)
{
	int		i;
	int		j;

	if (c->optionv == 0)
		return ;
	i = 1;
	j = c->nb - 1;
	ft_putendl(line);
	ft_printf("nb_a : %d		nb_b : %d\n", c->nb_a, c->nb_b);
	ft_printf("stack a:		stack b:\n");
	while (i < (c->nb + 1))
	{
		if (j < c->nb_a)
			ft_printf("%8d", c->stack_a[j]);
		else
			ft_printf("%8.d", 0);
		if (j < c->nb_b)
			ft_printf("%8d", c->stack_b[j]);
		else
			ft_printf("%8.d", 0);
		ft_printf("\n");
		j--;
		i++;
	}
	ft_printf("nombre de coup joue : %d\n", c->nb_played++);
}
