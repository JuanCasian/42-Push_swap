/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivoting_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:12:59 by jcasian           #+#    #+#             */
/*   Updated: 2019/02/06 15:12:59 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** gets the index of the next number smaller than the pivot
*/

int		get_next_index(t_stack *a, int pivot)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = a->head;
	while (tmp)
	{
		if (tmp->val <= pivot)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

/*
** rotates the stack into the closest number that is smaller than
** the pivot
*/

void	get_next_smaller(t_stack *a, t_stack *b, int pivot)
{
	int index;
	int movements;

	index = get_next_index(a, pivot);
	movements = a->len;
	if (index > a->len / 2)
	{
		movements -= index;
		while (movements--)
			call_and_print(a, b, "rra");
	}
	else
	{
		while (index--)
			call_and_print(a, b, "ra");
	}
}
