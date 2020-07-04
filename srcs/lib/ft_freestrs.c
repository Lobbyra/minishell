/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 13:42:17 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/04 13:42:20 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
