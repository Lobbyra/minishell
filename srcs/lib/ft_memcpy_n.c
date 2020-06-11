/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 10:17:50 by jecaudal          #+#    #+#             */
/*   Updated: 2020/04/20 10:19:28 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_memcpy_n(void *s1, void *s2, unsigned int n)
{
	unsigned char *t_s1;
	unsigned char *t_s2;

	t_s1 = (unsigned char *)s1;
	t_s2 = (unsigned char *)s2;
	while (t_s1 - (unsigned char*)s1 < n)
	{
		*t_s1 = *t_s2;
		t_s1++;
		t_s2++;
	}
	return (t_s1);
}
