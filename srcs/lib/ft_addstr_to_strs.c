/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstr_to_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 14:57:58 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/24 15:42:12 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function will add a string at the end of an array of strings by
**	by reallocation. The array must be ended by NULL.
*/

#include "minishell.h"

char		**ft_addstr_to_strs(char **strs, char *to_add)
{
	char	**new;
	int		i;
	int		len_strs;

	i = 0;
	len_strs = ft_strarrlen(strs);
	if (!(new = (char**)malloc(sizeof(char*) * (len_strs + 2))))
		return (NULL);
	while (i < len_strs)
	{
		new[i] = ft_strdup(strs[i]);
		i++;
	}
	new[i++] = ft_strdup(to_add);
	new[i] = NULL;
	return (new);
}
