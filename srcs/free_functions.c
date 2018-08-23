//header

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
