/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 14:51:44 by jcasian           #+#    #+#             */
/*   Updated: 2018/08/20 13:33:15 by jcasian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	valid_str(char *str)
{
	int i;
	
	i = -1;
	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != '-' && (!(str[i] >= '0' &&
						str[i] <= '9')))
			return (0);
	}
	return (1);
}

static char	**single_str(char *str)
{
	char	**res;

	if (!(valid_str(str)))
		put_error();
	if (!(res = ft_strsplit(str, ' ')))
		put_error();
	return (res);
}

static int	single_num(char *str)
{
	int	i;
	int	nums;

	i = 0;
	nums = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '-'))
			i++;
		if (str[i] && str[i] >= '0' && str[i] <= '9')
			nums++;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
			i++;
	}
	if (nums == 1)
		return (1);
	else
		return (0);
}

static char	**multiple_args(int ac, char **av)
{
	int 	i;
	int		j;
	char	**res;

	i = 1;
	j = 0;
	if (!(res = (char**)malloc(sizeof(char*) * ac)))
		put_error();
	while (i < ac)
	{
		if (valid_str(av[i]) && single_num(av[i]))
		{
			if (!(res[j] = ft_strdup(av[i])))
				put_error();
		}
		else
			put_error();
		i++;
	}
	return (res);

}

int		*get_input(int ac, char **av)
{
	int		*p_input;
	char	**p_str;

	if (ac == 2)
		p_str = single_str(av[1]);
	else if (ac > 2)
		p_str = multiple_args(ac, av);

	p_input = NULL;
	return (p_input);
}
