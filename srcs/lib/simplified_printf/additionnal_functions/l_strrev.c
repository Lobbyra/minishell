/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_strrev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:55:31 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/08 12:55:36 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

void	l_strrev(char *str)
{
	char			*t_begin;
	char			*t_end;
	unsigned int	len;
	char			temp;

	t_begin = str;
	t_end = str;
	len = l_strlen(str);
	while (*t_end)
		t_end++;
	t_end--;
	while (t_begin - str < len / 2)
	{
		temp = *t_begin;
		*t_begin = *t_end;
		*t_end = temp;
		t_begin++;
		t_end--;
	}
}
