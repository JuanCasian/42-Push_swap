/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:39:32 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/17 10:44:23 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_result(t_stack *a, t_stack *b)
{
	if (is_ascending(a) && !b->head)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int		main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;
	int		gres;
	int		flag;

	if (ac == 1)
		put_error();
	stack_a = input_parsing(ac, &av[1]);
	stack_b = new_stack();
	flag = 1;
	while (flag)
	{
		print_stack(stack_a, 'a');
		print_stack(stack_b, 'b');
		line = NULL;
		if ((gres = get_next_line_sin(STDIN_FILENO, &line)) < 0)
			put_error();
		else if (gres == 0)
			flag = 0;
		free(line);
	}
	print_result(stack_a, stack_b);
	return (0);
}
