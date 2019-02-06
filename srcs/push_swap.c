/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:56:22 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/19 20:51:59 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (0);
	a = input_parsing(ac, &av[1]);
	if (is_ascending(a) || a->len == 1)
		return (0);
	b = new_stack();
	if (a->len < 30)
		small_sort(a, b, NOT_SILENCED);
	else
		big_sort(a, b);
	return (0);
}
