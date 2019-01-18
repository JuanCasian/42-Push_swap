/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:39:32 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/17 19:55:01 by jcasian          ###   ########.fr       */
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

/*
** This function will check if the user's input is valid and if so
** it will do the respective function on the stacks
*/

void		validate_and_apply(t_stack *a, t_stack *b, char *str)
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
		print_stack(stack_a, 'a');
		print_stack(stack_b, 'b');
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
