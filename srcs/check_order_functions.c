/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:59:59 by jcasian           #+#    #+#             */
/*   Updated: 2018/09/20 21:01:34 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_bstack(t_push_swap *ps)
{
	t_stack *tmp;

	if (ps->b)
	{
		if (ps->b > ps->a)
			return (0);
		tmp = ps->b;
		while (tmp->next)
		{
			if (tmp->val < tmp->next->val)
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}

static int	is_ordered(t_push_swap *ps)
{
	t_stack	*tmp;
	int		prev;

	prev = 2147483647;
	if (ps->a)
	{
		tmp = ps->a;
		while (tmp->next)
		{
			if (tmp->val > tmp->next->val)
				return (0);
			tmp = tmp->next;
		}
	}
	if (check_bstack(ps) == 0)
		return (0);
	return (1);
}

void		check_repetition(t_push_swap *ps)
{
	t_stack	*runner;
	t_stack *tmp;
	int		counter;

	if (ps->a)
	{
		tmp = ps->a;
		while (tmp)
		{
			runner = ps->a;
			counter = 0;
			while (runner)
			{
				if (tmp->val == runner->val)
					counter++;
				runner = runner->next;
			}
			if (counter != 1)
				put_error();
			tmp = tmp->next;
		}
	}
}

void		check_final_order(t_push_swap *ps)
{
	if (is_ordered(ps) && !(ps->b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int			both_ordered(t_push_swap *ps)
{
	if (!(is_ordered(ps)))
		return (0);
	return (1);
}
