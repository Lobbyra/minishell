/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lobbyra <Lobbyra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 07:29:46 by Lobbyra           #+#    #+#             */
/*   Updated: 2020/06/10 14:46:54 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup_n(char *str, int n)
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
	return (new);
}
