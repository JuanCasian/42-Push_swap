/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calling_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 20:09:25 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/19 21:01:46 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** This function will check if the user's input is valid and if so
** it will do the respective function on the stacks
*/

void	validate_and_apply(t_stack *a, t_stack *b, char *str)
{
	if (!(ft_strcmp(str, "sa")))
		swap(a);
	else if (!(ft_strcmp(str, "sb")))
		swap(b);
	else if (!(ft_strcmp(str, "ss")))
		swap_s(a, b);
	else if (!(ft_strcmp(str, "pa")))
		push(b, a);
	else if (!(ft_strcmp(str, "pb")))
		push(a, b);
	else if (!(ft_strcmp(str, "ra")))
		rotate(a);
	else if (!(ft_strcmp(str, "rb")))
		rotate(b);
	else if (!(ft_strcmp(str, "rr")))
		rotate_r(a, b);
	else if (!(ft_strcmp(str, "rra")))
		rev_rotate(a);
	else if (!(ft_strcmp(str, "rrb")))
		rev_rotate(b);
	else if (!(ft_strcmp(str, "rrr")))
		rev_rotate_r(a, b);
	else
		put_error();
}

/*
** prints the instruction and calls the necesary operation
*/

void	call_and_print(t_stack *a, t_stack *b, char *str)
{
	ft_printf("%s\n", str);
	validate_and_apply(a, b, str);
}
