/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 19:19:10 by jcasian           #+#    #+#             */
/*   Updated: 2019/01/16 19:50:54 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Function to check each char inside the array of strings 
**	to see if all are valid numbers
**/

static int	is_numeric(char **strings)
{
	int		i;
	int		j;

	i = -1;
	while (strings[++i])
	{
		j = -1;
		while (strings[i][++j])
		{
			if (strings[i][j] != ' ' && !(strings[i][j] >= '0' &&
						strings[i][j] <= '9') && strings[i][j] != '-')
				return (0);
		}
	}
	return (1);
}

/*
**	Funtion to convert input from a char array into integers array
**	Making the validations to later convert into the linked lists
**/

void		input_parsing(int ac, char **input)
{
	char	**strings;

	if (ac == 2)
		strings = ft_strsplit(input[0], ' ');
	else
		strings = input;
	if (!(is_numeric(strings)))
		put_error();
}
