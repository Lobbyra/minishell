/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_strgen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 10:55:16 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/25 10:55:32 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*l_strgen(char c, int n)
{
	char *new;
	char *i_new;

	if (n > 0 && !(new = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	else if (n <= 0 && !(new = (char*)malloc(sizeof(char) * 1)))
		return (NULL);
	i_new = new;
	while (n > 0)
	{
		*i_new = c;
		n--;
		i_new++;
	}
	*i_new = '\0';
	return (new);
}
