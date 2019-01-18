/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:49:56 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/17 19:59:13 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** swaps the first 2 elements of the stack
*/

void	swap(t_stack *s)
{
	t_node	*tmp;

	if (!s || !s->head || !s->head->next)
		return ;
	if (s->len == 2)
		s->tail = s->head;
	tmp = s->head->next;
	s->head->next = s->head->next->next;
	tmp->next = s->head;
	s->head = tmp;
}

void	swap_s(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}
