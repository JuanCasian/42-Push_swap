/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 12:09:11 by jcasian           #+#    #+#             */
/*   Updated: 2019/02/06 12:09:13 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Finds the numbers which are the division of the subgroups to later
** separate them. This numbers are added to the pivots array.
*/

void	get_pivots(t_stack *ord, int *pivots)
{
	int		index;
	int		i;
	int		j;
	int		moving_index;
	t_node	*tmp;

	pivots[0] = ord->len < 200 ? 5 : 15;
	index = ord->len / pivots[0];
	i = 1;
	j = 1;
	tmp = ord->head;
	moving_index = index;
	while (j <= pivots[0])
	{
		if (i == moving_index)
		{
			pivots[j] = tmp->val;
			moving_index += index;
			j++;
		}
		tmp = tmp->next;
		i++;
	}
}

/*
** Returns wether there is a smaller number than the pivot or not
*/

int		num_smaller_pivot(int pivot, t_stack *a)
{
	t_node *tmp;

	tmp = a->head;
	while (tmp)
	{
		if (tmp->val < pivot)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/*
** Uses the pivots numbers to send smaller groups of numbers to b stack
*/

void	send_to_b(t_stack *a, t_stack *b, int *pivots)
{
	int current_piv;

	current_piv = 0;
	while (++current_piv <= pivots[0])
	{
		while (num_smaller_pivot(pivots[current_piv], a))
		{
			get_next_smaller(a, b, pivots[current_piv]);
			call_and_print(a, b, "pb");
		}
	}
	while (a->head != NULL)
		call_and_print(a, b, "pb");
}

/*
** Frees the node of the copy stack created
*/

void	free_ord(t_stack *ord)
{
	t_node *tmp;
	t_node *eraser;

	tmp = ord->head;
	ord->head = NULL;
	ord->tail = NULL;
	ord->len = 0;
	while (tmp)
	{
		eraser = tmp;
		tmp = tmp->next;
		eraser->val = 0;
		eraser->next = NULL;
		free(eraser);
	}
}

/*
** Sorts stacks by dividing them into smaller subgroups and then using
** small sort. By dividing the stack, the number of movements decreases
** significantly.
*/

void	big_sort(t_stack *a, t_stack *b)
{
	t_stack *ord;
	int		pivots[40];

	ord = copy_stack(a);
	small_sort(ord, b, SILENCED);
	get_pivots(ord, pivots);
	send_to_b(a, b, pivots);
	ascending_sort(a, b);
	free_ord(ord);
	free(ord);
}
