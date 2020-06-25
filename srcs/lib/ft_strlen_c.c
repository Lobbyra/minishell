/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 17:37:56 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/25 17:38:55 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		l_strlen_c(char *str, char c)
{
	char *temp;

	temp = str;
	if (!str)
		return (0);
	while (*temp && *temp != c)
		temp++;
	return (temp - str);
}
