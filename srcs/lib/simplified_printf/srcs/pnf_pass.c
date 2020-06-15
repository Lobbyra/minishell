/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnf_pass.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:30:49 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/28 10:13:04 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "l_printf.h"

void	pnf_pass_trash(char **str)
{
	while (**str && **str != '%')
		*str += 1;
}

void	pnf_pass_field(char **str)
{
	while (**str == '-' || **str == '0' ||
	l_isnum(**str) == TRUE || **str == '*')
		*str += 1;
}

void	pnf_pass_prec(char **str)
{
	if (**str == '.')
		*str += 1;
	if (**str == '*')
		*str += 1;
	else
		while (l_isnum(**str) == TRUE)
			*str += 1;
}

void	pnf_pass_conv(char **str, t_pnf_flags flags)
{
	if (**str == '%')
		*str += 1;
	if (flags & FLAG_FIELD)
		pnf_pass_field(str);
	if (flags & FLAG_PREC)
		pnf_pass_prec(str);
	if (**str)
		*str += 1;
}
