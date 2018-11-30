/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:33:46 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/30 11:09:06 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		ft_check_unicity(int argc, int *nbs)
{
	int		tmp;
	int		i;
	int		j;

	i = 0;
	while (i < argc)
	{
		tmp = nbs[i];
		j = 0;
		while (j < argc)
		{
			if (j != i && nbs[j] == tmp)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

static int		ft_check_if_only_nb_space(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if ((arg[i] == '-' && !arg[i + 1])
				|| (arg[i] == '-' && arg[i + 1] && !ft_isdigit(arg[i + 1])))
			return (-1);
		if (arg[i] != '-' && !ft_isdigit(arg[i]) && arg[i] != ' ')
			return (-1);
		i++;
	}
	return (1);
}

static int		ft_fill_stacks(t_check *c, char **tab)
{
	int		i;
	int		j;
	long	tmp;

	c->nb = ft_tablen(tab);
	if (!(c->stack_a = malloc(sizeof(int) * c->nb)))
		return (-1);
	i = 0;
	j = c->nb - 1;
	while (tab[i])
	{
		tmp = ft_atol(tab[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
		{
			free(c->stack_a);
			ft_del_tab(tab);
			return (-1);
		}
		c->stack_a[j--] = ft_atoi(tab[i++]);
	}
	ft_del_tab(tab);
	return (0);
}

int				ft_check_format(int argc, char **argv, t_check *c)
{
	char	*arg;
	char	**tab;

	c->optionv = 0;
	c->option_s = 0;
	c->optiont = 0;
	if (!(arg = ft_stick_args(argc, argv, c)))
		return (-1);
	if (ft_check_if_only_nb_space(arg) == -1)
		return (ft_strdelret(&arg, -1));
	if (!(tab = ft_strsplit(arg, ' ')))
		return (ft_strdelret(&arg, -1));
	ft_strdel(&arg);
	if (ft_fill_stacks(c, tab) == -1)
		return (-1);
	if (ft_check_unicity(c->nb, c->stack_a) == -1)
	{
		free(c->stack_a);
		return (-1);
	}
	return (0);
}
