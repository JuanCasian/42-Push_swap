/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_apply.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 21:06:17 by jcasian           #+#    #+#             */
/*   Updated: 2018/09/20 21:06:20 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validate_and_apply(t_push_swap *ps, char *str)
{
	if (!(ft_strcmp(str, "sa")))
		swap_a(ps);
	else if (!(ft_strcmp(str, "sb")))
		swap_b(ps);
	else if (!(ft_strcmp(str, "ss")))
		swap_s(ps);
	else if (!(ft_strcmp(str, "pa")))
		push_a(ps);
	else if (!(ft_strcmp(str, "pb")))
		push_b(ps);
	else if (!(ft_strcmp(str, "ra")))
		rotate_a(ps);
	else if (!(ft_strcmp(str, "rb")))
		rotate_b(ps);
	else if (!(ft_strcmp(str, "rr")))
		rotate_r(ps);
	else if (!(ft_strcmp(str, "rra")))
		rev_rotate_a(ps);
	else if (!(ft_strcmp(str, "rrb")))
		rev_rotate_b(ps);
	else if (!(ft_strcmp(str, "rrr")))
		rev_rotate_r(ps);
	else
		put_error();
}

void	call_and_print(t_push_swap *ps, char *str)
{
	validate_and_apply(ps, str);
	ft_printf("%s\n", str);
}
