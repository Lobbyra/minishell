//
// Created by Jérémy Caudal on 18/05/2020.
//

#include "minishell.h"

char	*ft_get_this_word(char *str)
{
	int		len;
	char	*temp;
	char	*result;

	while (*str == ' ')
		str++;
	temp = str;
	while (*temp != ' ' && *temp)
		temp++;
	len = temp - str;
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	temp = result;
	while (*str != ' ' && *str)
	{
		*temp = *str;
		str++;
		temp++;
	}
	*temp = '\0';
	return (result);
}
