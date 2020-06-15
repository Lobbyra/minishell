/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lobbyra <Lobbyra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 07:45:35 by Lobbyra           #+#    #+#             */
/*   Updated: 2020/06/13 16:10:47 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_c_finder(char c, char *set)
{
	char *temp;

	temp = set;
	if (temp)
		while (*temp)
		{
			if (*temp == c)
				return (TRUE);
			temp++;
		}
	return (FALSE);
}
