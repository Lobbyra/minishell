/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 16:44:40 by jecaudal          #+#    #+#             */
/*   Updated: 2020/04/01 16:47:47 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	ft_strarrfree(char **strs)
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
