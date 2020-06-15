/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnf_apply_field.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 10:41:49 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/28 10:43:55 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "l_printf.h"

static void	af_zero(t_pnf_infos *stock)
{
	int		len_raw;
	char	*injection;

	len_raw = l_strlen(stock->raw);
	if (stock->type & TYPE_PTR)
	{
		injection = l_strgen('0', (stock->field_len) - len_raw);
		stock->raw = l_strinject(stock->raw, injection, 2);
	}
	else if (stock->type & TYPE_INT && l_atoi(stock->raw) < 0)
	{
		injection = l_strgen('0', stock->field_len - len_raw);
		stock->raw = l_strinject(stock->raw, injection, 1);
	}
	else
	{
		injection = l_strgen('0', stock->field_len - len_raw);
		stock->raw = l_strjoindel(injection, stock->raw, 3);
	}
}

void		pnf_apply_field(t_pnf_infos *stock)
{
	int		len;

	if (stock->flags & FLAG_FIELD)
	{
		if ((stock->flags & FLAG_MINUS) || stock->field_len < 0)
		{
			len = stock->field_len - l_strlen(stock->raw);
			stock->raw = l_strjoindel(stock->raw, l_strgen(' ', len), 3);
		}
		else if (stock->flags & FLAG_ZERO)
			af_zero(stock);
		else
		{
			len = stock->field_len - l_strlen(stock->raw);
			stock->raw = l_strjoindel(l_strgen(' ', len), stock->raw, 3);
		}
	}
}
