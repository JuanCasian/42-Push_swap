/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 20:06:05 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/20 12:55:07 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

#include "libft.h"

typedef struct	s_stack
{
	int				val;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_push_swap
{
	t_stack	*a;
	t_stack	*b;
	int		asize;
	int		bsize;
}				t_push_swap;

t_push_swap		*initiate_structure(void);
void			put_error(void);
int				*get_input(int ac, char **av, t_push_swap *p);
t_stack			*new_elem(int input);
void			add_endelem(t_stack **head, t_stack *new_elem);
void			init_stack(t_push_swap *ps, int *p_input);




#endif
