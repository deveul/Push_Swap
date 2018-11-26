/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:23:06 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/26 17:49:29 by vrenaudi         ###   ########.fr       */
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
	i = c->a;
	while (i >= 0)
	{
		j = c->a;
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

static void	ft_init_rev_swap(t_check *c, t_swap *s)
{
	int		i;
	int		j;

	i = 0;
	s->revsort = ft_memalloc(sizeof(int) * c->nb_a);
	j = c->a;
	while (i < c->nb_a)
	{
		s->revsort[i] = s->sort[j];
		i++;
		j--;
	}
	i = 0;
	while (i < c->nb)
		i++;
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
	ft_init_rev_swap(&c, &s);
	//ft_sort_stack(&c, &s);
	if (c.nb < 10)
		ft_sort_stack2(&c, &s);
	else
		ft_sort_stack3(&c, &s);
	free(c.stack_a);
	free(c.stack_b);
	return (0);
}
