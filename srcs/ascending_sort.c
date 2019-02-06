/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascending_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:00:27 by jcasian           #+#    #+#             */
/*   Updated: 2019/02/06 14:00:28 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Gets the index of the max node in b
*/

int     get_max_index(t_stack *b)
{
    int		i;
	int		index;
	int		max;
	t_node	*tmp;

	i = 0;
	max = b->head->val;
	index = 0;
	tmp = b->head;
	while (tmp)
	{
		if (tmp->val > max)
		{
			max = tmp->val;
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}

/*
** Rotate to get the max node in b
*/

void    get_max(t_stack *a, t_stack *b)
{
    int index;
    int movements;
    
    index = get_max_index(b);
    movements = b->len;
    if (index > b->len / 2)
    {
        movements -= index;
        while (movements--)
            call_and_print(a, b, "rrb");
    }
    else
    {
        while (index--)
            call_and_print(a, b, "rb");
    }
}

/*
** Sorting numbers back to a stack
*/

void    ascending_sort(t_stack *a, t_stack *b)
{
    while (!is_ascending(a) || !is_descending(b) ||
    a->head->val < b->head->val)
    {
        get_max(a, b);
        if (is_descending(b))
            break ;
        call_and_print(a, b, "pa");
    }
    while (b->head)
        call_and_print(a, b, "pa");
}
