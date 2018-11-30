/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:23:06 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/30 11:19:08 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_init_checker(t_check *c)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	c->nb_played = 0;
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
	{
		ft_dprintf(c->wfd, "KO\n");
		return (-1);
	}
	while (i < c->nb_a)
	{
		if (c->stack_a[i] >= c->stack_a[i - 1])
		{
			ft_dprintf(c->wfd, "KO\n");
			return (-1);
		}
		i++;
	}
	ft_dprintf(c->wfd, "OK\n");
	return (1);
}

static int	ft_instruction(t_check *c, char *line)
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
	else
		return (-1);
	return (0);
}

static int	ft_run(t_check *c)
{
	char	*line;

	while (get_next_line(c->rfd, &line) > 0)
	{
		if (ft_instruction(c, line) == -1)
		{
			ft_dprintf(c->wfd, "Error\n");
			free(c->stack_a);
			free(c->stack_b);
			return (ft_strdelret(&line, -1));
		}
		ft_print_stack(c, line);
		ft_strdel(&line);
	}
	ft_is_it_sort(c);
	free(c->stack_a);
	free(c->stack_b);
	if (c->optiont == 1)
		close(c->wfd);
	if (c->rfd != 0)
		close(c->rfd);
	return (0);
}

int			main(int argc, char **argv)
{
	t_check	c;

	if (argc == 1)
		return (0);
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
	ft_option_trace(&c);
	ft_init_checker(&c);
	ft_print_stack(&c, NULL);
	if (ft_run(&c) == -1)
		return (-1);
	return (0);
}
