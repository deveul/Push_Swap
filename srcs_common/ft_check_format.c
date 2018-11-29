/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:33:46 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/29 15:02:25 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs_checker/checker.h"
#include "../srcs_push_swap/push_swap.h"

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

static int		ft_check_if_only_nb_space(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '-' && !ft_isdigit(str[i]) && str[i] != ' ')
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

static int		ft_stick_args(int argc, char **argv, t_check *c, char *arg)
{
	int		i;

	i = 2;
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-v"))
			c->optionv = 1;
		else if (ft_strequ(argv[i], "-s"))
			c->option_s = 1;
		else
		{
			if (!(arg = ft_strjoinfree(arg, " ")))
				return (ft_strdelret(&arg, -1));
			if (!(arg = ft_strjoinfree(arg, argv[i])))
				return (ft_strdelret(&arg, -1));
		}
		i++;
	}
	return (0);
}

int				ft_check_format(int argc, char **argv, t_check *c)
{
	char	*arg;
	char	**tab;

	c->optionv = 0;
	c->option_s = 0;
	if (!(arg = ft_strdup(argv[1])))
		exit(0);
	if (ft_stick_args(argc, argv, c, arg) == -1)
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
		ft_del_tab(tab);
		return (-1);
	}
	return (0);
}
