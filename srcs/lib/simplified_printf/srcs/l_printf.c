/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:14:32 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/28 14:46:48 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "l_printf.h"
#include <stdio.h>

static int	pnf_print(char *str, t_bool is_conv, t_pnf_flags flags)
{
	int count;

	count = 0;
	if (is_conv == TRUE)
	{
		if (flags & FLAG_CHARNULL)
			write(1, "\0", 1);
		while (str && *str)
		{
			write(1, str, 1);
			str++;
			count++;
		}
	}
	else
	{
		while (*str && *str != '%')
		{
			write(1, str, 1);
			str++;
			count++;
		}
	}
	return (count);
}

int			l_printf(char *str, ...)
{
	va_list		args;
	int			printed;
	t_pnf_infos *info;

	printed = 0;
	va_start(args, str);
	info = NULL;
	while (str && *str)
	{
		if (*str == '%')
		{
			info = pnf_get_info(str, args);
			printed += pnf_print(info->raw, TRUE, info->flags);
			pnf_pass_conv(&str, info->flags);
			l_free(2, info->raw, info);
		}
		printed += pnf_print(str, FALSE, 0);
		pnf_pass_trash(&str);
	}
	va_end(args);
	return (printed);
}
