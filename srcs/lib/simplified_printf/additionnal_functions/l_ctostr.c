/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_ctostr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:12:59 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/25 13:13:30 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*l_ctostr(char c)
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
