//Header

#include "push_swap.h"

t_stack	*new_elem(int input)
{
	t_stack *new;

	if (!(new = (t_stack*)malloc(sizeof(t_stack))))
		put_error();
	new->val = input;
	new->next = NULL;
	return (new);
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
		tmp->next = new;
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
