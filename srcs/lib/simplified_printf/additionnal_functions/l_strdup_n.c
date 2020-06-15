/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_strdup_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:12:16 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/27 15:23:25 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

char	*l_strdup_n(char *str, int n)
{
	int		i;
	char	*new;

	i = 0;
	if (!str ||
		!(new = (char*)malloc(sizeof(char) * (l_strlen_n(str, n) + 1))))
		return (NULL);
	while (str[i] && ((n > 0 && i < n) || n < 0))
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
