/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_until.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 15:24:22 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/25 17:50:00 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  This function will move forward your ptr while char c is not seen.
*/

void	ft_skip_until(char **ptr, char c)
{
	if (ptr)
	{
		while (**ptr != c && **ptr)
			(*ptr)++;
	}
}
