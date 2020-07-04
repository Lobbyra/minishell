/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_cutter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 13:45:42 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/04 13:46:29 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Return the sequence of chars until \0 or a chars in sep.
**
**	Dependances :
**	- ft_c_finder
*/

static int	word_len(char *str, char *sep)
{
	int count;

	count = 0;
	if (!str && !sep)
		return (0);
	while (ft_c_finder(*str, sep) == FALSE && *str)
	{
		count++;
		str++;
	}
	return (count);
}

char		*ft_word_cutter(char *str, char *sep)
{
	char *new;
	char *i_new;

	if (!(new = (char*)malloc(sizeof(char) * (word_len(str, sep) + 1))))
		return (NULL);
	i_new = new;
	while (ft_c_finder(*str, sep) == FALSE && *str)
	{
		*i_new = *str;
		i_new++;
		str++;
	}
	*i_new = '\0';
	return (new);
}
