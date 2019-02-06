/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 08:32:21 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/17 10:29:48 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** creates new empty stack
*/

t_stack		*new_stack(void)
{
	t_stack	*res;

	if (!(res = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	res->head = NULL;
	res->tail = NULL;
	res->len = 0;
	return (res);
}

/*
** Create a new node and assing the value
*/

t_node		*new_node(int val)
{
	t_node	*res;

	if (!(res = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	res->val = val;
	res->next = NULL;
	return (res);
}

/*
**	Adds nodes to the end of the stack
*/

t_stack		*add_node_end(t_stack *s, int val)
{
	t_node *tmp;

	if (!(tmp = new_node(val)))
		put_error();
	if (!s->head && !s->tail)
	{
		s->head = tmp;
		s->tail = tmp;
	}
	else
	{
		s->tail->next = tmp;
		s->tail = s->tail->next;
	}
	s->len++;
	return (s);
}

/*
** Prints the stack, useful for debug
*/

void		print_stack(t_stack *s, char c)
{
	t_node	*tmp;

	tmp = s->head;
	ft_printf("Stack (%c):\tlen: %i\n", c, s->len);
	while (tmp)
	{
		ft_printf("|%i|->", tmp->val);
		tmp = tmp->next;
	}
	ft_printf("(null)\n");
}

/*
** Creates a copy of the stack passed in as parameter and returns it
*/

t_stack		*copy_stack(t_stack *src)
{
	t_stack *res;
	t_node	*tmp;

	if (!src || !src->head || !src->tail || src->len == 0)
		put_error();
	res = new_stack();
	tmp = src->head;
	while (tmp)
	{
		res = add_node_end(res, tmp->val);
		tmp = tmp->next;
	}
	return (res);
}