/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:34:24 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/29 18:36:42 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_atoi(char *str)
{
	unsigned int i;
	unsigned int nb;
	unsigned int neg;

	i = 0;
	nb = 0;
	neg = 0;
	if (!str)
		return (0);
	while (ft_isspace(str[i]) == TRUE)
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg++;
	while (ft_isnum(str[i]) == TRUE)
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (neg % 2 == 1)
		return (nb * (-1));
	else
		return (nb);
}