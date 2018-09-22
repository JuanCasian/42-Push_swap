//header

#include "push_swap.h"

static int	find_mid_number(t_stack *stack, int size)
{
	t_stack	*tmp;
	int		current;
	int		res;
	int		counter;

	counter = 0;
	res = -2147483648;
	while (counter < size)
	{
		current = 2147483647;
		tmp = stack;
		while (tmp)
		{
			if (tmp->val < current && tmp->val > res)
				current = tmp->val;
			tmp = tmp->next;
		}
		res = current;
		counter++;
	}
	return (res);
}

static void	divide_bstack(t_push_swap *ps)
{
	int		final_size;
	int		mid_number;

	final_size = ps->bsize / 2;
	if (ps->bsize % 2 == 0)
		mid_number = find_mid_number(ps->b, final_size);
	else
		mid_number = find_mid_number(ps->b, final_size + 1);
	while (ps->bsize > final_size)
	{
		if (ps->b->val < mid_number)
			call_and_print(ps, "rb");
		else
			call_and_print(ps, "pa");
	}
}


static void	divide_astack(t_push_swap *ps)
{
	int		final_size;
	int		mid_number;

	final_size = ps->asize / 2;
	if (ps->asize % 2 == 0)
		mid_number = find_mid_number(ps->a, final_size);
	else
		mid_number = find_mid_number(ps->a, final_size + 1);
	while (ps->asize > final_size)
	{
		if (ps->a->val  > mid_number)
			call_and_print(ps, "ra");
		else
			call_and_print(ps, "pb");
	}
}

void		divide_arr(t_push_swap *ps, char c)
{
	if (c == 'a')
		divide_astack(ps);
	else
		divide_bstack(ps);
}
