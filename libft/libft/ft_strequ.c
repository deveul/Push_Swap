/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 19:30:00 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/04/19 15:21:15 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (!s1[i] && s2[i])
		return (0);
	if (!s2[i] && s1[i])
		return (0);
	if (s1[i] != s2[i])
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}
