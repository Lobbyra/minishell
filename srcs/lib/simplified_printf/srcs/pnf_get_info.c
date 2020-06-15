/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnf_get_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:13:55 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/28 13:57:14 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "l_printf.h"

static int	pnf_get_field_len(char *str, va_list args)
{
	int n;
	int wildcard;

	str++;
	n = 0;
	wildcard = 0;
	while (*str == '0' || *str == '-')
		str++;
	while (l_isnum(*str) == TRUE || *str == '*')
		if (*str == '*')
		{
			wildcard = va_arg(args, int);
			n = -1;
			str++;
		}
		else
		{
			n = l_atoi(str);
			while (l_isnum(*str) == TRUE)
				str++;
			wildcard = -1;
		}
	if (n != -1)
		return (n);
	return (wildcard);
}

static int	pnf_get_prec_len(char *str, va_list args)
{
	while (*str != '.' && *str)
		str++;
	if (*str)
		str++;
	if (*str == '*')
	{
		return (va_arg(args, int));
	}
	else
		return (l_atoi(str));
	return (0);
}

t_pnf_infos	*pnf_get_info(char *str, va_list args)
{
	t_pnf_infos *info;

	if (!(info = (t_pnf_infos*)malloc(sizeof(t_pnf_infos))))
		return (NULL);
	info->flags = pnf_get_flags(str);
	if (info->flags & FLAG_PREC)
		info->prec_len = pnf_get_prec_len(str, args);
	if (info->flags & FLAG_FIELD)
		info->field_len = pnf_get_field_len(str, args);
	info->type = pnf_get_type(str, info->flags & 1, info->flags & 2);
	info->raw = pnf_get_raw(info, args);
	if (info->flags & FLAG_PREC)
		pnf_apply_prec(info);
	if (info->flags & FLAG_FIELD)
		pnf_apply_field(info);
	return (info);
}
