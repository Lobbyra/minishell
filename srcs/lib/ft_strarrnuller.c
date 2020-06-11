/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrnuller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 08:50:31 by jecaudal          #+#    #+#             */
/*   Updated: 2020/04/02 08:52:04 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

char	**ft_strarrnuller(char **tab, unsigned int size)
{
	char			**new;
	unsigned int	i;

	i = 0;
	if (!tab)
		return (NULL);
	if (!(new = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
