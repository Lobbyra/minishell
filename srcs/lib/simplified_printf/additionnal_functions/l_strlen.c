/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_strlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 18:02:51 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/28 10:42:35 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

unsigned int		l_strlen(char *str)
{
	char *temp;

	temp = str;
	if (!str)
		return (0);
	while (*temp)
		temp++;
	return (temp - str);
}
