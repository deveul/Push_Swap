/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:33:46 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/21 10:18:24 by vrenaudi         ###   ########.fr       */
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

static int		ft_check_if_only_nb(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] && argv[i][j] != '-' && !ft_isdigit(argv[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int				ft_check_format(int argc, char **argv, t_check *check)
{	
	if (argc == 1)
		return (-1);
	else if (ft_check_if_only_nb(argc, argv) == -1)
		return (-1);
	else if (!(check->pile_a = ft_fill_nbs(argc, argv)))
		return (-1);
	else if (ft_check_unicity((argc - 1), check->pile_a) == -1)
		return (-1);
	ft_printf("format is OK\n");
	return (0);
}
