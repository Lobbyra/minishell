/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 18:31:54 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/30 18:33:01 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_ctostr(char c)
{
	char *new;

	if (c != '\0' && !(new = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	else if (c == '\0' && !(new = (char*)malloc(sizeof(char) * 1)))
		return (NULL);
	if (c != '\0')
	{
		new[0] = c;
		new[1] = '\0';
	}
	else
		new[0] = '\0';
	return (new);
}

