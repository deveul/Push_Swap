/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:33:46 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/28 15:40:18 by vrenaudi         ###   ########.fr       */
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

static int		*ft_fill_nbs(int argc, char **argv)
{
	int		*nbs;
	int		i;
	int		j;

	i = 1;
	j = argc - 2;
	if (!(nbs = ft_memalloc(sizeof(int) * argc)))
		return (NULL);
	i = 1;
	while (i < argc)
	{
		nbs[j] = ft_atoi(argv[i]);
		i++;
		j--;
	}
	return (nbs);
}

static int		ft_check_if_only_nb(int argc, char **argv, t_check *c)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (ft_strequ(argv[i], "-v"))
		{
			c->optionv = 1;
			i++;
		}
		while (argv[i] && argv[i][j])
		{
			if (argv[i][j] && argv[i][j] != '-' && !ft_isdigit(argv[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int				ft_check_format(int argc, char **argv, t_check *c)
{
	c->optionv = 0;
	if (argc == 1)
		return (-1);
	if (argc == 2 || (argc == 3 && ft_strequ(argv[2], "-v")))
		if (ft_check_if_only_nb(argc, argv, c) == -1)
			return (ft_check_format_str(argv[1], c, argc));
	c->nb = argc - 1;
	if (ft_check_if_only_nb(c->nb + 1, argv, c) == -1)
		return (-1);
	else if (!(c->stack_a = ft_fill_nbs(c->nb + 1, argv)))
		return (-1);
	else if (ft_check_unicity(c->nb, c->stack_a) == -1)
		return (-1);
	return (0);
}
