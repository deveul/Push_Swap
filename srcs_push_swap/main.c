/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:23:06 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/29 15:44:14 by vrenaudi         ###   ########.fr       */
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

	i = -1;
	if (!(s->sort = malloc(sizeof(int) * c->nb_a)))
	{
		free(c->stack_a);
		free(c->stack_b);
		exit(0);
	}
	while (++i < c->nb_a)
		s->sort[i] = c->stack_a[i];
	i = c->a;
	while (i >= 0)
	{
		j = c->a;
		while (j >= 0)
		{
			if (s->sort[i] < s->sort[j])
				ft_swap(&s->sort[i], &s->sort[j]);
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
	if (!(s->revsort = malloc(sizeof(int) * c->nb_a)))
	{
		free(s->sort);
		free(c->stack_a);
		free(c->stack_b);
		exit(0);
	}
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

static void	ft_solve_it(t_check *c, t_swap *s)
{
	if (ft_a_is_sort(c, s) == 1)
	{
		free(c->stack_a);
		free(c->stack_b);
		return ;
	}
	if (c->nb < 7)
		ft_sort_small(c, s);
	else
		ft_sort_big(c, s);
}

int			main(int argc, char **argv)
{
	t_check	c;
	t_swap	s;

	if (argc == 1)
		return (-1);
	c.nb = -1;
	if (ft_check_format(argc, argv, &c) == -1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	if (!(c.stack_b = malloc(sizeof(int) * c.nb)))
	{
		free(c.stack_a);
		return (-1);
	}
	ft_init_stack(&c);
	ft_init_swap(&c, &s);
	ft_init_rev_swap(&c, &s);
	ft_solve_it(&c, &s);
	free(c.stack_a);
	free(c.stack_b);
	free(s.sort);
	free(s.revsort);
	return (0);
}
