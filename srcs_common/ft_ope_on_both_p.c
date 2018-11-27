/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_on_both.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:54:13 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/27 15:12:40 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs_checker/checker.h"

void	ft_swap_both_p(t_check *c)
{
	ft_swap_a(c);
	ft_swap_b(c);
	ft_printf("ss\n");
}

void	ft_rotate_both_p(t_check *c)
{
	ft_rotate_a(c);
	ft_rotate_b(c);
	ft_printf("rr\n");
}

void	ft_reverse_rotate_both_p(t_check *c)
{
	ft_reverse_rotate_a(c);
	ft_reverse_rotate_b(c);
	ft_printf("rrr\n");
}
