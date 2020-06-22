/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 10:17:50 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/22 13:59:05 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "minishell.h"

void	*ft_memcpy_n(void *dst, void *src, unsigned int n)
{
	unsigned char *t_dst;
	unsigned char *t_src;

	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	while (t_dst - (unsigned char*)dst < n)
	{
		*t_dst = *t_src;
		t_dst++;
		t_src++;
	}
	return (t_dst);
}
