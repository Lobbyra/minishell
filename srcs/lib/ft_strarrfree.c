/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 16:44:40 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/15 13:57:09 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
