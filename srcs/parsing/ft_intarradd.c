/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarradd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:47:11 by jereligi          #+#    #+#             */
/*   Updated: 2020/07/16 16:57:08 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		*ft_intarradd(int *tab, int *size, int n)
{
	int	*new;
	int	i;

	i = 0;
	if (*size == 0)
	{
		if (!(new = (int *)malloc(sizeof(int) * (1))))
			return (NULL);
		new[0] = n;
		*size = 1;
	}
	else
	{
		if (!(new = (int *)malloc(sizeof(int) * (*size + 1))))
			return (NULL);
		while (i < *size)
		{
			new[i] = tab[i];
			i++;
		}
		new[i++] = n;
		*size = *size + 1;
	}
	free(tab);
	return (new);
}
