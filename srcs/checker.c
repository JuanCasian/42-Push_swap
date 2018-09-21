/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:59:53 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/27 20:04:54 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_push_swap	*ps;
	int			*p_input;
	char		*line;
	int			gres;
	int			flag;

	flag = 1;
	ps = initiate_structure();
	if (!(p_input = get_input(ac, av, ps)))
		exit(0);
	init_stack(ps, p_input);
	free(p_input);
	check_repetition(ps);
	print_stacks(ps);
	while (flag)
	{
		if ((gres = get_next_line_sin(ps->fd, &line)) < 0 )
			put_error();
		else if (gres == 0)
			flag = 0;
		else
			validate_and_apply(ps, line);
		print_stacks(ps);
	}
	print_stacks(ps);
	check_final_order(ps);
	return (0);
}
