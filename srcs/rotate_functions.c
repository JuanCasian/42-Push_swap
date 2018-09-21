/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 21:07:55 by jcasian           #+#    #+#             */
/*   Updated: 2018/09/20 21:07:57 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_push_swap *ps)
{
	t_stack *tmp;
	t_stack *last;

	if (!(ps->a) || !(ps->a->next))
		return ;
	last = ps->a;
	while (last->next)
		last = last->next;
	tmp = ps->a;
	ps->a = ps->a->next;
	tmp->next = last->next;
	last->next = tmp;
}

void	rotate_b(t_push_swap *ps)
{
	t_stack *tmp;
	t_stack *last;

	if (!(ps->b) || !(ps->b->next))
		return ;
	last = ps->b;
	while (last->next)
		last = last->next;
	tmp = ps->b;
	ps->b = ps->b->next;
	tmp->next = last->next;
	last->next = tmp;
}

void	rotate_r(t_push_swap *ps)
{
	rotate_a(ps);
	rotate_b(ps);
}
