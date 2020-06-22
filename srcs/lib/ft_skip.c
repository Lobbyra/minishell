/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 15:24:22 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/22 15:24:36 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  This function will move forward your ptr while c is at the **ptr.
*/

void	ft_skip(char **ptr, char c)
{
	if (ptr && c != '\0')
	{
		while (**ptr == c)
			ptr++;
	}
}
