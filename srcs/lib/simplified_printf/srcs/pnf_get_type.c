/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnf_get_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 14:32:41 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/28 13:25:00 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "l_printf.h"

t_pnf_type	pnf_get_type(char *str, t_bool is_field, t_bool is_prec)
{
	if (*str == '%')
		str++;
	if (is_field == 1)
		pnf_pass_field(&str);
	if (is_prec == 2)
		pnf_pass_prec(&str);
	if (*str == 'c')
		return (TYPE_CHAR);
	else if (*str == 's')
		return (TYPE_STR);
	else if (*str == 'p')
		return (TYPE_PTR);
	else if (*str == 'd')
		return (TYPE_INT);
	else if (*str == 'i')
		return (TYPE_INT);
	else if (*str == 'u')
		return (TYPE_UINT);
	else if (*str == 'x')
		return (TYPE_HEXMIN);
	else if (*str == 'X')
		return (TYPE_HEXCAP);
	else if (*str == '%')
		return (TYPE_POURC);
	return (TYPE_OTHER);
}
