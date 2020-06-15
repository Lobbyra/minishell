/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarrarrstrs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 14:47:13 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/15 15:27:29 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putarrarrstrs(char ***ptr, int size)
{
	int i;

	i = 0;
	if (ptr)
	{
		while (i < size)
		{
			ft_putarrstr(ptr[i], ", ");
			write(1, "\n", 1);
			i++;
		}
	}
}