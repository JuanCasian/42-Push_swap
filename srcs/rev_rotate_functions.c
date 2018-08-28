//header

#include "push_swap.h"

void	rev_rotate_a(t_push_swap *ps)
{
	t_stack *last;
	t_stack *new_last;

	if (!(ps->a) || !(ps->a->next))
		return ;
	new_last = ps->a;
	while (new_last->next->next)
		new_last = new_last->next;
	last = new_last->next;
	new_last->next = last->next;
	last->next = ps->a;
	ps->a = last;
}

void	rev_rotate_b(t_push_swap *ps)
{
	t_stack *last;
	t_stack *new_last;

	if (!(ps->b) || !(ps->b->next))
		return ;
	new_last = ps->b;
	while (new_last->next->next)
		new_last = new_last->next;
	last = new_last->next;
	new_last->next = last->next;
	last->next = ps->b;
	ps->b = last;
}

void	rev_rotate_r(t_push_swap *ps)
{
	rev_rotate_a(ps);
	rev_rotate_b(ps);
}
