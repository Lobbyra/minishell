/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_itoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeremyca <jeremyca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 09:53:33 by jeremyca          #+#    #+#             */
/*   Updated: 2020/01/08 15:13:26 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

static void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*string;

	i = 0;
	if (!(string = (char*)malloc(sizeof(char) * (int)size)))
		return (NULL);
	while (i < size)
	{
		string[i] = 'x';
		i++;
	}
	return ((void*)string);
}

static char	*int_min(char *str)
{
	int		i;
	char	*i_min;

	i = 0;
	i_min = "-2147483648";
	while (i_min[i])
	{
		str[i] = i_min[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*alloc(int n)
{
	char	*new;

	if (n >= 0)
	{
		if (!(new = (char*)ft_memalloc(sizeof(char) * (l_numlen(n) + 1))))
			return (NULL);
		new[l_numlen(n)] = '\0';
	}
	else if (n != -2147483648)
	{
		if (
		!(new = (char*)ft_memalloc(sizeof(char) * (l_numlen(n * -1) + 1 + 1))))
			return (NULL);
		new[0] = '-';
		new[l_numlen(n * -1) + 1] = '\0';
	}
	else if (n == -2147483648)
	{
		if (!(new = (char*)ft_memalloc(sizeof(char) * (12))))
			return (NULL);
		new = int_min(new);
	}
	else
		return (NULL);
	return (new);
}

char		*l_itoa(int n)
{
	int		i;
	char	*new;

	i = 0;
	new = alloc(n);
	if (!(new) || n == -2147483648)
		return (new);
	if (n < 0)
		n *= -1;
	while (new[i])
		i++;
	i--;
	if (n == 0)
		new[0] = '0';
	else
	{
		while ((n > 0 && i >= 0) || (n < 0 && i > 1))
		{
			new[i] = n % 10 + '0';
			n /= 10;
			i--;
		}
	}
	return (new);
}
