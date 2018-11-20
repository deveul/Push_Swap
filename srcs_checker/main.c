/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:23:06 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/20 19:02:13 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_swap_a(t_check *c)
{
	int		tmp;

	if (c->a < 1)
		return ;
	tmp = c->pile_a[c->a - 1];
	c->pile_a[c->a - 1] = c->pile_a[c->a];
	c->pile_a[c->a] = tmp;
}

static void	ft_swap_b(t_check *c)
{
	int		tmp;

	if (c->b < 1)
		return ;
	tmp = c->pile_b[c->b - 1];
	c->pile_b[c->b - 1] = c->pile_b[c->b];
	c->pile_b[c->b] = tmp;
}

static void	ft_push_a(t_check *c)
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

static void	ft_push_b(t_check *c)
{
	if (c->nb_a == 0)
		return ;
	c->b++;
	c->pile_b[c->b] = c->pile_a[c->a];
	c->pile_a[c->a] = -1000;
	c->nb_a--;
	c->a--;
	c->nb_b++;
}

static void ft_rotate_a(t_check *c)
{
	int		tmp;
	int		i;

	i = 0;
	tmp = c->pile_a[c->a];
	while (i + 1 < c->nb_a)
	{
		c->pile_a[i] = c->pile_a[i + 1];
		i++;
	}
	c->pile_a[c->a] = c->pile_a[0];
}

int		main(int argc, char **argv)
{
	t_check	check;
	char	*line;
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (ft_check_format(argc, argv, &check) == -1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	if (!(check.pile_b = malloc(sizeof(int) * (argc - 1))))
		return (-1);
	check.nb_a = argc - 1;
	check.a = check.nb_a - 1;
	check.nb_b = 0;
	check.b = check.nb_b - 1;
	while (i++ < argc)
		check.pile_b[j++] = -1000;
	i = 1;
	j = 0;
	while (i++ < argc)
		ft_printf("%d\n", check.pile_a[j++]);
	while (1)
	{
		ft_printf("nb_a : %d		nb_b : %d\n", check.nb_a, check.nb_b);
		if (get_next_line(0, &line) < 1)
			return (0);
		if (ft_strstr(line, "sa"))
			ft_swap_a(&check);
		else if (ft_strstr(line, "sb"))
			ft_swap_b(&check);
		else if (ft_strstr(line, "ss"))
		{
			ft_swap_a(&check);
			ft_swap_b(&check);
		}
		else if (ft_strstr(line, "pa"))
			ft_push_a(&check);
		else if (ft_strstr(line, "pb"))
			ft_push_b(&check);
		else if (ft_strstr(line, "ra"))
			ft_rotate_a(&check);
	/*	else if (line == "rb")
			ft_rotate_b(&check);
		else if (line == "rr")
		{
			ft_rotate_a(&check);
			ft_rotate_b(&check);
		}
		else if (line == "rra")
			ft_reverse_rotate_a(&check, 1);
		else if (line == "rrb")
			ft_reverse_rotate_b(&check, 1);
		else if (line == "rrr")
		{
			ft_reverse_rotate_a(&check, 1);
			ft_reverse_rotate_b(&check, 1);
		}*/
		i = 1;
		j = argc - 2;
		ft_printf("Pile a:		Pile b:\n");
		while (i++ < argc)
		{
			ft_printf("%d		%d\n", check.pile_a[j], check.pile_b[j]);
			j--;
		}
	}
	return (0);
}
