//Header

#include "push_swap.h"

void	swap_a(t_push_swap *ps)
{
	t_stack *tmp;

	if (!(ps->a) || !(ps->a->next))
		return ;
	tmp = ps->a->next;
	ps->a->next = ps->a->next->next;
	tmp->next = ps->a;
	ps->a = tmp;
}

void	swap_b(t_push_swap *ps)
{
	t_stack *tmp;

	if (!(ps->b) || !(ps->b->next))
		return ;
	tmp = ps->b->next;
	ps->b->next = ps->b->next->next;
	tmp->next = ps->b;
	ps->b = tmp;
}

void	swap_s(t_push_swap *ps)
{
	swap_b(ps);
	swap_a(ps);
}
