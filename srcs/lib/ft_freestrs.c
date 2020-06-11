//
// Created by Jérémy Caudal on 29/04/2020.
//

#include "minishell.h"

void	ft_freestrs(char **strs)
{
	char **temp;

	temp = strs;
	if (strs)
	{
		while (*temp)
		{
			free(*temp);
			temp++;
		}
		free(strs);
	}
}
