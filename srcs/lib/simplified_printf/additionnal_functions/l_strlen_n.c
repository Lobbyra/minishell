/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_strlen_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 18:02:51 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/25 13:35:08 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

unsigned int	l_strlen_n(char *str, int n)
{
	char *temp;

	temp = str;
	if (!str)
		return (0);
	while (*temp && ((n < 0) || (temp - str) - n))
		temp++;
	return (temp - str);
}
