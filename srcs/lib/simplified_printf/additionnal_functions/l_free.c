/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 08:01:03 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/08 13:37:48 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

void	l_free(int argc, ...)
{
	va_list argv;
	void	*to_free;

	va_start(argv, argc);
	while (argc > 0)
	{
		to_free = va_arg(argv, void*);
		if (to_free)
			free(to_free);
		argc--;
	}
}
