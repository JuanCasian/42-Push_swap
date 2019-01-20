/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 20:03:47 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/19 21:03:00 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Goes through the stack comparing the values to find the minimum
** and then returns the value of it
*/

int		get_min_index(t_stack *a)
{
	int		i;
	int		index;
	int		min;
	t_node	*tmp;

	i = 0;
	min = a->head->val;
	index = 0;
	tmp = a->head;
	while (tmp)
	{
		if (tmp->val < min)
		{
			min = tmp->val;
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}

/*
** rotates the stack until the smallest value gets to the head
** it decides which rotate method to use depending on the index of minimum
*/

void	get_min(t_stack *a, t_stack *b)
{
	int	index;
	int	movements;

	index = get_min_index(a);
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

/*
** This function will look for the smallest value and then put it to b stack
** until you get an ordered list and just push everything back to a
*/

void	small_sort(t_stack *a, t_stack *b)
{
	if (a && a->head && a->head->next)
		call_and_print(a, b, "sa");
	while (!is_ascending(a) || !is_descending(b) ||
			a->head->val < b->head->val)
	{
		get_min(a, b);
		if (is_ascending(a))
			break ;
		call_and_print(a, b, "pb");
	}
	while (b->head)
		call_and_print(a, b, "pa");
}
