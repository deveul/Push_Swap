/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:23:06 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/23 12:23:00 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init_stack(t_check *c)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i++ < (c->nb + 1))
		c->stack_b[j++] = 0;
	c->nb_a = c->nb;
	c->a = c->nb_a - 1;
	c->nb_b = 0;
	c->b = c->nb_b - 1;
}

static void	ft_init_swap(t_check *c, t_swap *s)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	s->sort = ft_memalloc(sizeof(int) * c->nb_a);
	while (i < c->nb_a)
	{
		s->sort[i] = c->stack_a[i];
		i++;
	}
	i = c->nb_a;
	while (i >= 0)
	{
		j = c->nb_a;
		while (j >= 0)
		{
			if (s->sort[i] < s->sort[j])
			{
				tmp = s->sort[i];
				s->sort[i] = s->sort[j];
				s->sort[j] = tmp;
			}
			j--;
		}
		i--;
	}
}

int			main(int argc, char **argv)
{
	t_check	c;
	t_swap	s;

	c.nb = -1;
	if (ft_check_format(argc, argv, &c) == -1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	if (!(c.stack_b = malloc(sizeof(int) * c.nb)))
		return (-1);
	ft_init_stack(&c);
	ft_init_swap(&c, &s);
	ft_sort_stack(&c, &s);
	free(c.stack_a);
	free(c.stack_b);
	return (0);
}
