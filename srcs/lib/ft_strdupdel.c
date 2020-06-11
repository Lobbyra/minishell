//
// Created by Jérémy Caudal on 30/04/2020.
//

#include "minishell.h"

char	*ft_strdupdel(char *str)
{
	int		i;
	char	*new;

	i = 0;
	if (!(new = (char*)malloc(sizeof(char) *
							  (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	free(str);
	new[i] = '\0';
	return (new);
}
