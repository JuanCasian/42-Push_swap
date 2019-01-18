/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:38:04 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/17 19:47:16 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Push the head of one stack into the top of the other
*/

void	push(t_stack *src, t_stack *target)
{
	t_node	*tmp;

	if (!src || !src->head)
		return ;
	src->len--;
	target->len++;
	tmp = src->head;
	src->head = src->head->next;
	tmp->next = target->head;
	target->head = tmp;
	if (target->len == 1)
		target->tail = target->head;
}
