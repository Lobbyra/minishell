/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:06:52 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/16 18:47:41 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_prompt(void)
{
	char *pwd;

	pwd = getcwd(NULL, MAX_PATH_LEN);
	l_printf("\nminishell[%s]$>", pwd);
	if (pwd != NULL)
		free(pwd);
}
