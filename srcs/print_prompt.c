/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:06:52 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/21 17:01:26 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_prompt(void)
{
	char *pwd;

	pwd = getcwd(NULL, MAX_PATH_LEN);
	l_printf("\n\033[32mminishell\033[37m[%s]$>", pwd);
	if (pwd != NULL)
		free(pwd);
}
