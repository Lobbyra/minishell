/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_this_word.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 13:42:42 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/04 13:42:49 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_this_word(char *str)
{
	int		len;
	char	*temp;
	char	*result;

	while (*str == ' ')
		str++;
	temp = str;
	while (*temp != ' ' && *temp)
		temp++;
	len = temp - str;
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	temp = result;
	while (*str != ' ' && *str)
	{
		*temp = *str;
		str++;
		temp++;
	}
	*temp = '\0';
	return (result);
}
