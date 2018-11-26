/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:23:06 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/26 18:06:06 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_print_stack(t_check *c)
{
	int		i;
	int		j;

	i = 1;
	j = c->nb - 1;
	system("clear");
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

static void	ft_init_checker(t_check *c)
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

static int	ft_is_it_sort(t_check *c)
{
	int		i;

	i = 1;
	if (c->nb_b != 0)
		return (-1);
	while (i < c->nb_a)
	{
		if (c->stack_a[i] >= c->stack_a[i - 1])
		{
			ft_printf("KO\n");
			return (-1);
		}
		i++;
	}
	ft_printf("OK\n");
	return (1);
}

static void	ft_instruction(t_check *c, char *line)
{
	if (ft_strequ(line, "sa"))
		ft_swap_a(c);
	else if (ft_strequ(line, "sb"))
		ft_swap_b(c);
	else if (ft_strequ(line, "ss"))
		ft_swap_both(c);
	else if (ft_strequ(line, "pa"))
		ft_push_a(c);
	else if (ft_strequ(line, "pb"))
		ft_push_b(c);
	else if (ft_strequ(line, "ra"))
		ft_rotate_a(c);
	else if (ft_strequ(line, "rb"))
		ft_rotate_b(c);
	else if (ft_strequ(line, "rr"))
		ft_rotate_both(c);
	else if (ft_strequ(line, "rra"))
		ft_reverse_rotate_a(c);
	else if (ft_strequ(line, "rrb"))
		ft_reverse_rotate_b(c);
	else if (ft_strequ(line, "rrr"))
		ft_reverse_rotate_both(c);
}

int			main(int argc, char **argv)
{
	t_check	c;
	char	*line;

	c.nb = -1;
	c.nb_played = 0;
	if (ft_check_format(argc, argv, &c) == -1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	if (!(c.stack_b = malloc(sizeof(int) * c.nb)))
		return (-1);
	ft_init_checker(&c);
	ft_print_stack(&c);
	while (get_next_line(0, &line) > 0)
	{
		ft_putendl(line);
//		sleep(1);
		ft_instruction(&c, line);
		ft_print_stack(&c);
//		c.nb_played++;
		ft_strdel(&line);
	}
//	ft_print_stack(&c);
	ft_is_it_sort(&c);
	free(c.stack_a);
	free(c.stack_b);
	return (0);
}
