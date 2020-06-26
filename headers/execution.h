/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:10:39 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/26 17:24:15 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# define MAX_PATH_LEN 4096

/*
**	Builtins functions
*/
int		pwd(int fd);
int		cd(char *path);
void	ft_exit(int err);
int		echo(char **job, int fd);
int		env(char **envp, int fd);
int		unset(char ***envp, char **job);
int		export(char ***envp, char **job, int fd);

/*
**	Builtins additionnal functions
*/
t_bool	is_var_exist(char **envp, char *arg);
void	print_envp_export(char **envp, int fd);
int		var_replacement(char **envp, char *arg);

#endif