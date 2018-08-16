/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 20:06:05 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/15 21:02:45 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

#include "libft.h"

typedef struct	s_stack
{
	int				val;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_push_swap
{
	t_stack	*a;
	t_stack	*b;
	int		asize;
	int		bsize;
}				t_push_swap;

#endif
