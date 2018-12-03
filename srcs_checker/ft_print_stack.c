/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:10:56 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/30 12:15:13 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_slower(t_check *c)
{
	int		i;

	i = 0;
	if (c->option_s == 0 || c->optiont != 0)
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

void		ft_option_trace(t_check *c)
{
	char	str[1];

	c->rfd = 0;
	c->wfd = 1;
	if (c->optiont == 1)
	{
		c->rfd = open("trace_push_swap", O_RDWR, 0777);
		if (read(c->rfd, str, 1) < 1)
			c->rfd = 0;
		else
		{
			close(c->rfd);
			c->rfd = open("trace_push_swap", O_RDWR, 0777);
		}
		c->wfd = open("trace_checker", O_CREAT | O_RDWR | O_TRUNC, 0777);
	}
}
