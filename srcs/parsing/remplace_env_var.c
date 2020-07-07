/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplace_env_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jeanxavier <Jeanxavier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 17:17:46 by jereligi          #+#    #+#             */
/*   Updated: 2020/07/07 17:26:26 by Jeanxavier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		remplace_env_var(char *new, char *value)
{
	int i;

	i = 0;
	while (value[i])
	{
		new[i] = value[i];
		i++;
	}
	new[i] = '\0';
	return (i);
}
