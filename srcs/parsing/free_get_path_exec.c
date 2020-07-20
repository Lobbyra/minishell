/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_get_path_exec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 18:35:25 by jereligi          #+#    #+#             */
/*   Updated: 2020/07/20 18:51:18 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_get_path_exec_one(char **path, char *exec, char **jobs, char *tmp)
{
	free_alloc(exec, path, jobs[0]);
	jobs[0] = tmp;
}

void	free_get_path_exec_two(char **path, char *exec, char **jobs, char *tmp)
{
	free_alloc(exec, path, jobs[2]);
	jobs[2] = tmp;
}
