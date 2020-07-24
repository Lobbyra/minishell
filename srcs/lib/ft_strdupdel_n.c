/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupdel_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 16:53:17 by jereligi          #+#    #+#             */
/*   Updated: 2020/07/24 18:05:05 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdupdel_n(char *str, int n)
{
	int		i;
	char	*new;

	i = 0;
	if (!str ||
		!(new = (char*)malloc(sizeof(char) * (ft_strlen_n(str, n) + 1))))
		return (NULL);
	while (str[i] && (n > 0 || n < 0))
	{
		new[i] = str[i];
		i++;
		n--;
	}
	new[i] = '\0';
	free(str);
	return (new);
}
