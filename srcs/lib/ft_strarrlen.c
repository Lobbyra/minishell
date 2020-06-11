/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:45:56 by jecaudal          #+#    #+#             */
/*   Updated: 2020/04/02 09:14:28 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strarrlen(char **tab)
{
	char **count;

	count = tab;
	if (!tab)
		return (0);
	while (*count)
		count++;
	return (count - tab);
}
