/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 21:03:58 by jcasian           #+#    #+#             */
/*   Updated: 2018/09/20 21:06:01 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_elem(int input)
{
	t_stack *new_elem;

	if (!(new_elem = (t_stack*)malloc(sizeof(t_stack))))
		put_error();
	new_elem->val = input;
	new_elem->next = NULL;
	return (new_elem);
}

void	add_endelem(t_stack **head, t_stack *new_elem)
{
	t_stack *tmp;

	if (!(*head))
	{
		*head = new_elem;
		return ;
	}
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_elem;
	}
}

void	init_stack(t_push_swap *ps, int *p_input)
{
	t_stack *tmp;
	int		i;

	i = -1;
	while (++i < ps->asize)
	{
		tmp = new_elem(p_input[i]);
		add_endelem(&(ps->a), tmp);
	}
}

void	print_stacks(t_push_swap *ps)
{
	t_stack *tmp;

	tmp = ps->a;
	ft_printf("Stack (a): ");
	while (tmp)
	{
		ft_printf("|%i|->", tmp->val);
		tmp = tmp->next;
	}
	ft_printf("(null)\n");
	tmp = ps->b;
	ft_printf("Stack (b): ");
	while (tmp)
	{
		ft_printf("|%i|->", tmp->val);
		tmp = tmp->next;
	}
	ft_printf("(null)\n");
}
