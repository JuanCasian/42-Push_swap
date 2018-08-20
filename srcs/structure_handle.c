/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 14:38:56 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/18 16:46:15 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap		*initiate_structure(void)
{
	t_push_swap	*ps;

	if (!(ps = (t_push_swap*)malloc(sizeof(t_push_swap))))
		put_error();
	ps->a = NULL;
	ps->b = NULL;
	ps->asize = 0;
	ps->bsize = 0;
	return (ps);
}
