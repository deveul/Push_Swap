/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_on_both.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:54:13 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/22 14:52:31 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs_checker/checker.h"

void	ft_swap_both(t_check *c)
{
	ft_swap_a(c);
	ft_swap_b(c);
}

void	ft_rotate_both(t_check *c)
{
	ft_rotate_a(c);
	ft_rotate_b(c);
}

void	ft_reverse_rotate_both(t_check *c)
{
	ft_reverse_rotate_a(c);
	ft_reverse_rotate_b(c);
}
