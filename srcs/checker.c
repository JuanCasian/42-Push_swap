/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:39:32 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/19 21:03:27 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** This function checks that the stack a is on ascending order
** and that the stack b is empty and then prints the result
*/

static void	print_result(t_stack *a, t_stack *b)
{
	if (is_ascending(a) && !b->head)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int			main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;
	int		gres;
	int		flag;

	if (ac == 1)
		return (0);
	stack_a = input_parsing(ac, &av[1]);
	stack_b = new_stack();
	flag = 1;
	while (flag)
	{
//		print_stack(stack_a, 'a');
//		print_stack(stack_b, 'b');
		line = NULL;
		if ((gres = get_next_line_sin(STDIN_FILENO, &line)) < 0)
			put_error();
		else if (gres == 0)
			flag = 0;
		else
			validate_and_apply(stack_a, stack_b, line);
		free(line);
	}
	print_result(stack_a, stack_b);
	return (0);
}
