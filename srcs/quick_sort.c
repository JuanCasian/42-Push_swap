//header

#include "push_swap.h"

static int	a_ordered(t_push_swap *ps)
{
	t_stack	*tmp;

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
	return (1);
}

static int	b_ordered(t_push_swap *ps)
{
	t_stack *tmp;

	if (ps->b)
	{
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

static void	quick_sortb(t_push_swap *ps)
{
	t_stack *tmp;

	while (!(b_ordered(ps)))
	{
		tmp = ps->b;
		while (tmp->next)
			tmp = tmp->next;
		if (ps->b->val < tmp->val)
		{
			call_and_print(ps, "rrb");
			call_and_print(ps, "sb");
		}
		else if (ps->b->val < ps->b->next->val)
			call_and_print(ps, "sb");
		else
			call_and_print(ps, "rb");
	}
}


static void	quick_sorta(t_push_swap *ps)
{
	t_stack *tmp;

	while (!(a_ordered(ps)))
	{
		tmp = ps->a;
		while (tmp->next)
			tmp = tmp->next;
		if (ps->a->val < tmp->val)
		{
			call_and_print(ps, "rra");
			call_and_print(ps, "sa");
		}
		else if (ps->->val < ps->b->next->val)
			call_and_print(ps, "sb");
		else
			call_and_print(ps, "rb");
	}
}

void	quick_sort(t_push_swap *ps, char c)
{
	if (c == 'a')
		quick_sorta(ps);
	else
		quick_sortb(ps);
}
