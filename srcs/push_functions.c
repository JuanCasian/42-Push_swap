// header

#include "push_swap.h"

void	push_a(t_push_swap *ps)
{
	t_stack *tmp;

	tmp = ps->b;
	ps->b = ps->b->next;
	tmp->next = ps->a;
	ps->a = tmp;
}

void	push_b(t_push_swap *ps)
{
	t_stack *tmp;

	tmp = ps->a;
	ps->a = ps->a->next;
	tmp->next = ps->b;
	ps->b = tmp;
}
