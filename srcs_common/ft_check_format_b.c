/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:33:46 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/29 12:41:30 by vrenaudi         ###   ########.fr       */
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


int				ft_check_format_b(int argc, char **argv, t_check *c)
{
	int		i;
	int		j;
	int		tmp;
	char	*arg;
	char	**tab;

	i = 2;
	c->nb = -1;
	c->optionv = 0;
	if (argc == 1)
		return (-1);
	else
	{
		arg = ft_strdup(argv[1]);
		while (i < argc)
		{
			if (ft_strequ(argv[i], "-v"))
				c->optionv = 1;
			else
			{
				arg = ft_strjoinfree(arg, " ");
				arg = ft_strjoinfree(arg, argv[i]);
			}
			i++;
		}
	}
	if (ft_check_if_only_nb_space(arg) == -1)
		return (-1);
	if (!(tab = ft_strsplit(arg, ' ')))
		return (-1);
	i = 0;
	while (tab[i])
		i++;
	c->nb = i;
	if (!(c->stack_a = ft_memalloc(sizeof(int) * i)))
		return (-1);
	i = 0;
	j = c->nb - 1;
	while (tab[i])
	{
		tmp = ft_atol(tab[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
			return (-1);
		c->stack_a[j--] = ft_atoi(tab[i++]);
	}
	if (ft_check_unicity(c->nb, c->stack_a) == -1)
		return (-1);
	return (0);
}
