/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 21:07:17 by jcasian           #+#    #+#             */
/*   Updated: 2018/09/20 21:07:22 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_push_swap *ps)
{
	t_stack *tmp;

	if (!ps->b)
		return ;
	(ps->asize)++;
	(ps->bsize)--;
	tmp = ps->b;
	ps->b = ps->b->next;
	tmp->next = ps->a;
	ps->a = tmp;
}

void	push_b(t_push_swap *ps)
{
	t_stack *tmp;

	if (!ps->a)
		return ;
	(ps->asize)--;
	(ps->bsize)++;
	tmp = ps->a;
	ps->a = ps->a->next;
	tmp->next = ps->b;
	ps->b = tmp;
}
