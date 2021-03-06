/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 09:14:59 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/17 19:39:56 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Free the array of strings used in the input parsing
*/

void	free_strings(char ***strings)
{
	char	**s;
	int		i;

	s = *strings;
	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}
