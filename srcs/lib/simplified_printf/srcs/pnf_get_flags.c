/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnf_get_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:02:31 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/27 14:29:16 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "l_printf.h"

static t_bool	pnf_is_prec(char *str)
{
	if (*str == '%')
		str++;
	if (*str == '0' || *str == '-')
		str++;
	while (l_isnum(*str) == TRUE || *str == '*')
		str++;
	if (*str == '.')
		return (TRUE);
	return (FALSE);
}

static t_bool	pnf_is_field(char *str)
{
	if (*str == '%')
		str++;
	if (*str == '0' || *str == '-')
		return (TRUE);
	if (l_isnum(*str) == TRUE || *str == '*')
		return (TRUE);
	return (FALSE);
}

t_pnf_flags		pnf_get_flags(char *str)
{
	t_pnf_flags flags;

	flags = 0;
	if (pnf_is_field(str) == TRUE)
		flags |= FLAG_FIELD;
	if (pnf_is_prec(str) == TRUE)
		flags |= FLAG_PREC;
	if (pnf_is_field(str) == TRUE && str[1] == '0')
		flags |= FLAG_ZERO;
	else if (pnf_is_field(str) == TRUE && str[1] == '-')
		flags |= FLAG_MINUS;
	return (flags);
}
