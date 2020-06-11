/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:49:06 by jecaudal          #+#    #+#             */
/*   Updated: 2020/04/02 09:19:17 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

char	**ft_strarrdup(char **arr)
{
	char	**new;
	char	**temp;

	if (!(new = (char**)malloc(sizeof(char*) * (ft_strarrlen(arr) + 1))))
		return (NULL);
	temp = new;
	while (*arr)
	{
		*temp = ft_strdup(*arr);
		arr++;
		temp++;
	}
	*temp = NULL;
	return (new);
}
