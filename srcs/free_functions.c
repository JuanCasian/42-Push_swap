/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 21:07:44 by jcasian           #+#    #+#             */
/*   Updated: 2018/09/20 21:07:46 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_parsed_str(char ***str)
{
	int i;

	i = -1;
	if (!str)
		return ;
	while (str[0][++i])
		free(str[0][i]);
	if (*str)
		free(*str);
	*str = NULL;
}
