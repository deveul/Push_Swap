/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:23:06 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/21 12:01:42 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_is_it_sort(t_check *c)
{
	int		i;

	i = 1;
	if (c->nb_b != 0)
		return (-1);
	while (i < c->nb_a)
	{
		if (c->pile_a[i] >= c->pile_a[i - 1])
			return (-1);
		i++;
	}
	return (1);
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
	while (get_next_line(0, &line) > 0)
	{
		ft_printf("nb_a : %d		nb_b : %d\n", check.nb_a, check.nb_b);
		if (ft_strequ(line, "sa"))
			ft_swap_a(&check);
		else if (ft_strequ(line, "sb"))
			ft_swap_b(&check);
		else if (ft_strequ(line, "ss"))
			ft_swap_both(&check);
		else if (ft_strequ(line, "pa"))
			ft_push_a(&check);
		else if (ft_strequ(line, "pb"))
			ft_push_b(&check);
		else if (ft_strequ(line, "ra"))
			ft_rotate_a(&check);
		else if (ft_strequ(line, "rb"))
			ft_rotate_b(&check);
		else if (ft_strequ(line, "rr"))
			ft_rotate_both(&check);
		else if (ft_strequ(line, "rra"))
			ft_reverse_rotate_a(&check);
		else if (ft_strequ(line, "rrb"))
			ft_reverse_rotate_b(&check);
		else if (ft_strequ(line, "rrr"))
			ft_reverse_rotate_both(&check);
		i = 1;
		j = argc - 2;
		ft_printf("Pile a:		Pile b:\n");
		while (i++ < argc)
		{
			ft_printf("%d		%d\n", check.pile_a[j], check.pile_b[j]);
			j--;
		}
		ft_strdel(&line);
	}
	i = ft_is_it_sort(&check);
	if (i == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(check.pile_a);
	free(check.pile_b);
	return (0);
}
