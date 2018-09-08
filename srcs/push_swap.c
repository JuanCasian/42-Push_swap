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
//	print_stacks(ps);
	return (0);
}
