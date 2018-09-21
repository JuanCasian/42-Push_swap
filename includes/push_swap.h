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
	int		div_size;
	int		fd;
}				t_push_swap;

t_push_swap		*initiate_structure(void);
void			put_error(void);
int				*get_input(int ac, char **av, t_push_swap *p);
t_stack			*new_elem(int input);
void			add_endelem(t_stack **head, t_stack *new_elem);
void			init_stack(t_push_swap *ps, int *p_input);
void			print_stacks(t_push_swap *ps);
void			free_parsed_str(char ***str);
void			check_final_order(t_push_swap *ps);
void			check_initial_order(t_push_swap *ps);
void			swap_a(t_push_swap *ps);
void			swap_b(t_push_swap *ps);
void			swap_s(t_push_swap *ps);
void			push_a(t_push_swap *ps);
void			push_b(t_push_swap *ps);
void			rotate_a(t_push_swap *ps);
void			rotate_b(t_push_swap *ps);
void			rotate_r(t_push_swap *ps);
void			rev_rotate_a(t_push_swap *ps);
void			rev_rotate_b(t_push_swap *ps);
void			rev_rotate_r(t_push_swap *ps);
void			validate_and_apply(t_push_swap *ps, char *str);
void			check_repetition(t_push_swap *ps);
int				both_ordered(t_push_swap *ps);
int				get_lastVal(t_stack *mystack);
void			call_and_print(t_push_swap *ps, char *str);

#endif
