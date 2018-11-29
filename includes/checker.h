/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:26:49 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/11/29 18:38:45 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/printf/ft_printf.h"
# include "../libft/libft/get_next_line.h"
# include <fcntl.h>

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
	int			rfd;
	int			wfd;
	int			optionv;
	int			option_s;
	int			optiont;
}				t_check;

int				ft_check_format(int argc, char **argv, t_check *check);
void			ft_print_stack(t_check *c, char *line);
void			ft_option_trace(t_check *c);
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
