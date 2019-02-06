/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 10:41:13 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/19 21:02:28 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Checks if the order is ascending in the stack
*/

int	is_ascending(t_stack *s)
{
	t_node	*tmp;

	if (!s || !s->head)
		return (1);
	tmp = s->head;
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/*
**	Checks if the order is descending in the stack
*/

int	is_descending(t_stack *s)
{
	t_node	*tmp;

	if (!s || !s->head)
		return (1);
	tmp = s->head;
	while (tmp->next)
	{
		if (tmp->val < tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
