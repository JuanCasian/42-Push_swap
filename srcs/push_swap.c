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
	while  (!(both_ordered(ps)))
	{
		if (ps->b)
			if (ps->b->val > ps->a->val)
			{
				push_a(ps);
				ft_printf("pa\n");
			}
		if (ps->a->val > ps->a->next->val)
		{
			swap_a(ps);
			ft_printf("sa\n");
		}
		else
		{
			push_b(ps);
			ft_printf("pb\n");
		}
		print_stacks(ps);
	}		
	while (ps->b)
	{
		push_a(ps);
		ft_printf("pa\n");
	}
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
	print_stacks(ps);
	push_swap(ps);
	return (0);
}
