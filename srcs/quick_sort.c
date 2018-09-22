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
	while (!(b_ordered(ps)))
	{
		if (ps->bsize >= 3 && ps->b->val < ps->b->next->next->val)
			call_and_print(ps, "rb");
		else if (ps->b->val < ps->b->next->val)
			call_and_print(ps, "sb");
		else if (ps->b->next->val > ps->b->next->next->val)
		{
			call_and_print(ps, "pa");
			call_and_print(ps, "sb");	
			call_and_print(ps, "pb");
		}
	}
}


static void	quick_sorta(t_push_swap *ps)
{
	while (!(a_ordered(ps)))
	{
		if (ps->asize >= 3 && ps->a->val > ps->a->next->next->val)
			call_and_print(ps, "ra");
		else if (ps->a->val > ps->a->next->val)
			call_and_print(ps, "sa");
		else if (ps->a->next->val > ps->a->next->next->val)
		{	
			call_and_print(ps, "pb");
			call_and_print(ps, "sa");	
			call_and_print(ps, "pa");
		}
	}
}

void	quick_sort(t_push_swap *ps, char c)
{
	if (c == 'a')
		quick_sorta(ps);
	else
		quick_sortb(ps);
}
