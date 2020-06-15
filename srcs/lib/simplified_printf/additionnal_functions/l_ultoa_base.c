/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_ultoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:25:14 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/27 15:09:31 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

static void	lub_computing(char *buf, unsigned long nbr, char *base_to)
{
	unsigned int len_base;

	len_base = l_strlen(base_to);
	while (nbr > 0)
	{
		*buf = base_to[nbr % len_base];
		nbr /= len_base;
		buf++;
	}
	*buf = '\0';
}

char		*l_ultoa_base(unsigned long nbr, char *base_to)
{
	char	buf[64];

	lub_computing(buf, nbr, base_to);
	l_strrev(buf);
	return (l_strdup(buf));
}
