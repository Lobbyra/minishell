/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_strjoindel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:12:28 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/08 13:12:40 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

char			*l_strjoindel(char *s1, char *s2, int param)
{
	char	*i_new;
	char	*new;

	if (!(new = (char*)malloc(sizeof(char)
	* ((l_strlen(s1) + l_strlen(s2) + 1)))))
		return (NULL);
	i_new = new;
	if (s1 || s2)
	{
		i_new = l_memcpy_n(i_new, s1, l_strlen(s1));
		i_new = l_memcpy_n(i_new, s2, l_strlen(s2));
	}
	*i_new = '\0';
	if (param == 1)
		free(s1);
	if (param == 2)
		free(s2);
	if (param == 3)
	{
		free(s1);
		free(s2);
	}
	return (new);
}
