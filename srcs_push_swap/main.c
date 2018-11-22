/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:23:06 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/22 10:49:10 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init_swap(t_check *c)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i++ < (c->nb + 1))
		c->pile_b[j++] = 0;
	c->nb_a = c->nb;
	c->a = c->nb_a - 1;
	c->nb_b = 0;
	c->b = c->nb_b - 1;
}

int			main(int argc, char **argv)
{
	t_check	c;

	c.nb = -1;
	if (ft_check_format(argc, argv, &c) == -1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	if (!(c.pile_b = malloc(sizeof(int) * c.nb)))
		return (-1);
	ft_init_swap(&c);
	ft_printf("sa\n");
	ft_printf("pb\n");
	ft_printf("pb\n");
	ft_printf("pb\n");
//	ft_printf("rr\n");
//	ft_printf("rrr\n");
	ft_printf("sa\n");
	ft_printf("pa\n");
	ft_printf("pa\n");
	ft_printf("pa\n");
	free(c.pile_a);
	free(c.pile_b);
	return (0);
}
