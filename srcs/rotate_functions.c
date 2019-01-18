/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 19:02:26 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/17 19:49:58 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Rotate the stack so that the first element becomes the last one
*/

void	rotate(t_stack *s)
{
	t_node *tmp;

	if (!s || !s->head || !s->head->next)
		return ;
	tmp = s->head;
	s->head = s->head->next;
	tmp->next = s->tail->next;
	s->tail->next = tmp;
	s->tail = tmp;
}

void	rotate_r(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}
