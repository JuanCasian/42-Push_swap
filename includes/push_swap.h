/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:12:10 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/19 20:57:43 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# define SILENCED 1
# define NOT_SILENCED 0

# include "libft.h"

typedef	struct	s_node
{
	int				val;
	struct s_node	*next;
}				t_node;

typedef struct	s_stack
{
	int		len;
	t_node	*head;
	t_node	*tail;
}				t_stack;

t_stack			*input_parsing(int ac, char **av);
void			put_error();
t_stack			*new_stack(void);
t_stack			*add_node_end(t_stack *s, int val);
void			free_strings(char ***strings);
void			print_stack(t_stack *s, char c);
long long		ft_atoll(char *str);
int				is_ascending(t_stack *s);
void			push(t_stack *src, t_stack *target);
void			rev_rotate(t_stack *s);
void			rev_rotate_r(t_stack *a, t_stack *b);
void			rotate(t_stack *s);
void			rotate_r(t_stack *a, t_stack *b);
void			swap(t_stack *s);
void			swap_s(t_stack *a, t_stack *b);
void			validate_and_apply(t_stack *a, t_stack *b, char *str);
void			call_and_print(t_stack *a, t_stack *b, char *str);
void			small_sort(t_stack *a, t_stack *b, int silence);
int				is_descending(t_stack *s);
void    		big_sort(t_stack *a, t_stack *b);
t_stack			*copy_stack(t_stack *src);
void			ascending_sort(t_stack *a, t_stack *b);

#endif
