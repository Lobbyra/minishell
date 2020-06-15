/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_utoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:08:27 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/28 13:56:58 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

static int	ulen(unsigned int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char		*l_utoa(unsigned int n)
{
	char *str;
	char *temp;

	if (n == 0)
		return (l_strdup("0"));
	if (!(str = (char*)malloc(sizeof(char) * (ulen(n) + 1))))
		return (NULL);
	temp = str;
	while (n != 0)
	{
		*temp = (n % 10) + '0';
		n /= 10;
		temp++;
	}
	*temp = '\0';
	l_strrev(str);
	return (str);
}
