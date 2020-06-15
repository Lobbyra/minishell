/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_ptox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:10:14 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/15 11:32:08 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

char	*l_ptox(void *ptr)
{
	char *result;

	if (ptr == NULL)
		result = l_strdup("0");
	else
		result = l_ultoa_base((long)ptr, "0123456789abcdef");
	result = l_strjoindel("0x", result, 2);
	return (result);
}
