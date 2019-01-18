/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 19:13:31 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/17 19:50:35 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Last element in the stack becomes the first one.
*/

void	rev_rotate(t_stack *s)
{
	t_node	*penultimate;

	if (!s || !s->head || !s->head->next)
		return ;
	penultimate = s->head;
	while (penultimate->next->next)
		penultimate = penultimate->next;
	penultimate->next = s->tail->next;
	s->tail->next = s->head;
	s->head = s->tail;
	s->tail = penultimate;
}

void	rev_rotate_r(t_stack *a, t_stack *b)
{
	rev_rotate(a);
	rev_rotate(b);
}
