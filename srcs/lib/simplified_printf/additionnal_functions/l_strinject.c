/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_strinject.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:01:04 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/25 13:11:09 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

char	*l_strinject(char *str, char *injection, unsigned int index)
{
	char	*new;
	char	*i_new;

	if (!(new = (char *)malloc(sizeof(char) *
	(l_strlen(str) + l_strlen(injection) + 1))))
		return (NULL);
	i_new = new;
	if (index > l_strlen(str))
		index = l_strlen(str);
	i_new = l_memcpy_n(i_new, str, index);
	i_new = l_memcpy_n(i_new, injection, l_strlen(injection));
	i_new = l_memcpy_n(i_new, str + index, l_strlen(str) - index);
	*i_new = '\0';
	l_free(2, str, injection);
	return (new);
}
