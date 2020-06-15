/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnf_get_raw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 10:34:40 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/28 14:44:09 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "l_printf.h"

static char	*gr_char(t_pnf_infos *infos, char c)
{
	if (c == '\0')
	{
		if (infos->flags & FLAG_FIELD)
			infos->field_len--;
		infos->flags |= FLAG_CHARNULL;
	}
	return (l_ctostr(c));
}

char		*pnf_get_raw(t_pnf_infos *infos, va_list args)
{
	char	*temp;

	if (infos->type == TYPE_CHAR)
		return (gr_char(infos, va_arg(args, int)));
	else if (infos->type == TYPE_STR)
	{
		temp = va_arg(args, char *);
		if (!temp)
			return (l_strdup("(null)"));
		return (l_strdup(temp));
	}
	else if (infos->type == TYPE_PTR)
		return (l_ptox(va_arg(args, void *)));
	else if (infos->type == TYPE_INT)
		return (l_itoa(va_arg(args, int)));
	else if (infos->type == TYPE_UINT)
		return (l_utoa(va_arg(args, int)));
	else if (infos->type == TYPE_HEXMIN)
		return (l_itox(va_arg(args, int), FALSE));
	else if (infos->type == TYPE_HEXCAP)
		return (l_itox(va_arg(args, int), TRUE));
	else if (infos->type == TYPE_POURC)
		return (l_strdup("%"));
	return (NULL);
}
