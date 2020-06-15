/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnf_apply_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 10:41:12 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/28 14:46:36 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "l_printf.h"

static void		pp_exceptions_extended(t_pnf_infos *info)
{
	char	*injection;
	int		len_result;

	len_result = l_strlen(info->raw);
	if (info->prec_len > 0 && info->type & TYPE_INT
		&& l_ispos(l_atoi(info->raw)) == FALSE)
	{
		injection = l_strgen('0', info->prec_len - (len_result - 1));
		info->raw = l_strinject(info->raw, injection, 1);
	}
	else if (info->type & TYPE_PTR)
	{
		injection = l_strgen('0', info->prec_len - (len_result - 2));
		info->raw = l_strinject(info->raw, injection, 2);
	}
}

static t_bool	pp_exceptions(t_pnf_infos *info)
{
	char	*result;

	if (info->type & TYPE_STR ||
		((info->type & TYPE_CHAR || info->type & TYPE_POURC)
		&& (info->prec_len = 1) == 1))
	{
		result = l_strdup_n(info->raw, info->prec_len);
		free(info->raw);
		info->raw = result;
	}
	else if ((info->prec_len > 0 && info->type & TYPE_INT
		&& l_ispos(l_atoi(info->raw)) == FALSE) || info->type & TYPE_PTR)
		pp_exceptions_extended(info);
	else if (l_strcmp(info->raw, "0") == 0 && info->prec_len == 0)
	{
		free(info->raw);
		info->raw = l_strdup("");
	}
	else
		return (FAILURE);
	return (SUCCESS);
}

void			pnf_apply_prec(t_pnf_infos *info)
{
	char	*injection;

	if (info->flags & FLAG_PREC && pp_exceptions(info) == FAILURE)
	{
		injection = l_strgen('0', info->prec_len - (l_strlen(info->raw)));
		info->raw = l_strjoindel(injection, info->raw, 3);
	}
}
