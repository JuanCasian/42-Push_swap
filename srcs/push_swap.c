/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 20:00:36 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/15 20:12:26 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_push_swap *ps)
{
	while(!(both_ordered(ps)))
	{
		while (ps->asize > ps->div_size)
			divide_arr(ps, 'a');
		quick_sort(ps, 'a');
		if (ps->b)
		{
			while (ps->bsize > ps->div_size)
				divide_arr(ps, 'b');
			quick_sort(ps, 'b');
		}
		div_size += 2;
	}
	while (b->stack)
		call_and_print(ps, "pa");
}

int		main(int ac, char **av)
{
	t_push_swap	*ps;
	int			*p_input;

	ps = initiate_structure();
	if (!(p_input = get_input(ac, av, ps)))
		exit(0);
	init_stack(ps, p_input);
	free(p_input);
	check_repetition(ps);
	push_swap(ps);
	return (0);
}
