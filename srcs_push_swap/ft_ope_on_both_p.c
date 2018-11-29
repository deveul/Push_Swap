/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_on_both.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:54:13 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/29 17:00:44 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap_both_p(t_check *c)
{
	ft_swap_a(c);
	ft_swap_b(c);
	ft_dprintf(c->wfd, "ss\n");
}

void	ft_rotate_both_p(t_check *c)
{
	ft_rotate_a(c);
	ft_rotate_b(c);
	ft_dprintf(c->wfd, "rr\n");
}

void	ft_reverse_rotate_both_p(t_check *c)
{
	ft_reverse_rotate_a(c);
	ft_reverse_rotate_b(c);
	ft_dprintf(c->wfd, "rrr\n");
}
