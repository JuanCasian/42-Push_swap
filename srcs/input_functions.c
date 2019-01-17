/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 19:19:10 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/17 10:31:09 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Function to check each char inside the array of strings
**	to see if all are valid numbers
*/

static int		is_numeric(char **strings)
{
	int		i;
	int		j;

	i = -1;
	while (strings[++i])
	{
		j = -1;
		while (strings[i][++j])
		{
			if (strings[i][j] != ' ' && !(strings[i][j] >= '0' &&
						strings[i][j] <= '9') && strings[i][j] != '-')
				return (0);
		}
	}
	return (1);
}

/*
**	This function will convert all strings into numbers and validate them
**	after that it will add them into the initial stack
*/

static t_stack	*get_initial_stack(char **strings)
{
	t_stack		*stack_a;
	int			i;
	long long	tmp;

	if (!(stack_a = new_stack()))
		return (NULL);
	i = -1;
	while (strings[++i])
	{
		tmp = ft_atoll(strings[i]);
		if (tmp < -2147483648 || tmp > 2147483647)
			put_error();
		stack_a = add_node_end(stack_a, (int)tmp);
	}
	return (stack_a);
}

/*
** Function to check if there is any repeating number
*/

static int		has_repetitions(t_stack *s)
{
	t_node	*runner;
	t_node	*tmp;
	int		counter;

	tmp = s->head;
	while (tmp)
	{
		runner = s->head;
		counter = 0;
		while (runner)
		{
			if (tmp->val == runner->val)
				counter++;
			runner = runner->next;
		}
		if (counter != 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/*
**	Function to convert input from a char array into linked list
**	Making the validations and checking for errors
*/

t_stack			*input_parsing(int ac, char **input)
{
	char	**strings;
	t_stack	*stack_a;

	if (ac == 2)
		strings = ft_strsplit(input[0], ' ');
	else
		strings = input;
	if (!(is_numeric(strings)))
		put_error();
	if (!(stack_a = get_initial_stack(strings)))
		put_error();
	if (has_repetitions(stack_a))
		put_error();
	if (strings != input)
		free_strings(&strings);
	return (stack_a);
}
