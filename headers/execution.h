/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:10:39 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/02 17:35:51 by jecaudal         ###   ########.fr       */
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
void	builtin_call_child(char **job, char *exit_stat, char ***envp);
int		redirector(int *pipes, int jobpos, t_bool is_pipe, t_stock *s);
int		instance_builder(t_stock *s, int jobpos, int *pipes, t_bool is_pipe);
void	builtin_call_parent(char **job, char *ex_stat, int fd, char ***envp);

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

/*
**	Sub function of redirector.
*/
char 	**rm_redir(char **job);
t_bool	is_in_redir(char **job);
t_bool	is_out_redir(char **job);
int		redirector_file_in(char **job);
int		redirector_file_out(t_stock *s, int jobpos);

#endif