/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:10:39 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/30 17:59:57 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# define MAX_PATH_LEN 4096


/*
**	Sub function of execution.
*/
t_bool	is_builtin(char *path);
int		jobs_caller(t_stock *s);
int		init_pipes(int **pipes, int n_jobs);
void	close_pipes(int *pipes, int n_pipes);
void	terminator(char ***jobs, int n_jobs, char *status);
int		builtin_caller(char **job, char *exit_stat, int is_child, char ***envp);
void	redirector(int *pipes, int jobpos, t_bool is_pipe, t_bool is_debug);
int		instance_builder(t_stock *s, int jobpos, int *pipes, t_bool is_pipe);

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