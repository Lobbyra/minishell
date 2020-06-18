/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 16:32:06 by jereligi          #+#    #+#             */
/*   Updated: 2020/06/18 16:40:13 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		n;
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	n = 0;
	while (s1[n])
		dst[i++] = s1[n++];
	n = 0;
	while (s2[n])
		dst[i++] = s2[n++];
	dst[i] = '\0';
	return (dst);
}
