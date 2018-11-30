/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stick_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 10:48:38 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/30 10:58:43 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		ft_set_option(t_check *c, char *str)
{
	if (ft_strequ(str, "-v"))
		return (c->optionv = 1);
	else if (ft_strequ(str, "-s1"))
		return (c->option_s = 1);
	else if (ft_strequ(str, "-s2"))
		return (c->option_s = 2);
	else if (ft_strequ(str, "-s3"))
		return (c->option_s = 3);
	else if (ft_strequ(str, "-t"))
		return (c->optiont = 1);
	return (-1);
}

char			*ft_stick_args(int argc, char **argv, t_check *c)
{
	int		i;
	char	*arg;

	i = 2;
	if (!(arg = ft_strdup(argv[1])))
		return (NULL);
	while (i < argc)
	{
		if (ft_set_option(c, argv[i]) < 1)
		{
			if (!(arg = ft_strjoinfree(arg, " ")))
			{
				ft_strdel(&arg);
				return (NULL);
			}
			if (!(arg = ft_strjoinfree(arg, argv[i])))
			{
				ft_strdel(&arg);
				return (NULL);
			}
		}
		i++;
	}
	return (arg);
}
