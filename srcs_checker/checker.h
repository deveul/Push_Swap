/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:26:49 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/23 12:23:25 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/printf/ft_printf.h"
# include "../libft/libft/get_next_line.h"

typedef struct	s_check
{
	int			*stack_a;
	int			*stack_b;
	int			nb;
	int			nb_a;
	int			nb_b;
	int			a;
	int			b;
	int			nb_played;
}				t_check;

int				ft_check_format(int argc, char **argv, t_check *check);
int				ft_check_format_str(char *str, t_check *c);
void			ft_swap_a(t_check *c);
void			ft_push_a(t_check *c);
void			ft_rotate_a(t_check *c);
void			ft_reverse_rotate_a(t_check *c);
void			ft_swap_b(t_check *c);
void			ft_push_b(t_check *c);
void			ft_rotate_b(t_check *c);
void			ft_reverse_rotate_b(t_check *c);
void			ft_swap_both(t_check *c);
void			ft_rotate_both(t_check *c);
void			ft_reverse_rotate_both(t_check *c);

#endif
