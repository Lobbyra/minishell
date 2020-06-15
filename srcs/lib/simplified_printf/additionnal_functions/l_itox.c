/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_itox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:02:41 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/27 14:10:47 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

char	*l_itox(int nbr, t_bool is_cap)
{
	unsigned long	n;
	char			*t_buf;
	char			*digits;
	char			buf[64];

	t_buf = buf;
	n = (unsigned long)nbr;
	if (is_cap == FALSE)
		digits = "0123456789abcdef";
	else
		digits = "0123456789ABCDEF";
	if (nbr == 0)
		return (l_strdup("0"));
	while (n > 0 && t_buf - buf < 8)
	{
		*t_buf = digits[n % 16];
		n /= 16;
		t_buf++;
	}
	*t_buf = '\0';
	l_strrev(buf);
	return (l_strdup(buf));
}
