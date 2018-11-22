/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:12:14 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/22 13:04:12 by vrenaudi         ###   ########.fr       */
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

int		ft_check_format_str(char *str, t_check *c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	if (ft_check_if_only_nb_space(str) == -1)
		return (-1);
	tab = ft_strsplit(str, ' ');
	while (tab[i])
		i++;
	c->nb = i;
	if (!(c->stack_a = ft_memalloc(sizeof(int) * c->nb)))
		return (-1);
	i = 0;
	j = c->nb - 1;
	while (tab[i])
	{
		c->stack_a[j] = ft_atoi(tab[i]);
		i++;
		j--;
	}
	if (ft_check_unicity(c->nb, c->stack_a) == -1)
		return (-1);
	return (0);
}
