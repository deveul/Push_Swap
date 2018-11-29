/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_and_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:42:52 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/29 16:58:35 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_do_and_print(t_check *c, t_cbv *cbv)
{
	int		i;

	i = 0;
	while (i++ < cbv->bestra)
		ft_rotate_a_p(c);
	i = 0;
	while (i++ < cbv->bestrb)
		ft_rotate_b_p(c);
	i = 0;
	while (i++ < cbv->bestrra)
		ft_reverse_rotate_a_p(c);
	i = 0;
	while (i++ < cbv->bestrrb)
		ft_reverse_rotate_b_p(c);
	i = 0;
	while (i++ < cbv->bestrrr)
		ft_reverse_rotate_both_p(c);
	i = 0;
	while (i++ < cbv->bestrr)
		ft_rotate_both_p(c);
	ft_push_b_p(c);
}
