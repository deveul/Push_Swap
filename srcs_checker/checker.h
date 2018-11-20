/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:26:49 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/20 19:02:11 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/printf/ft_printf.h"
# include "../libft/libft/get_next_line.h"

typedef struct	s_check
{
	int			*pile_a;
	int			*pile_b;
	int			nb_a;
	int			nb_b;
	int			a;
	int			b;
}				t_check;

int		ft_check_format(int argc, char **argv, t_check *check);

#endif
