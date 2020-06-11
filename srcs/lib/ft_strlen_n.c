/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lobbyra <Lobbyra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 07:30:38 by Lobbyra           #+#    #+#             */
/*   Updated: 2020/04/21 07:43:37 by Lobbyra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen_n(char *str, int n)
{
	char *temp;

	temp = str;
	if (!str)
		return (0);
	while (*temp && ((n < 0) || (temp - str) - n))
		temp++;
	return (temp - str);
}
