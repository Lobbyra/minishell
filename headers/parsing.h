/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 16:29:39 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/23 18:55:14 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define ERR_QUOTE1 "minishell: unexpected EOF while looking for matching `"
# define ERR_QUOTE2 "\'\nminishell: syntax error unexpected end of file\n"
# define ERR_PIPE1 "minishell: syntax error unexpected end of file\n"
# define ERR_PIPE2 "minishell: syntax error near unexpected token `|'\n"
# define ERR_PIPE3 "minishell: syntax error near unexpected token `;'\n"
# define ERR_REDICTION "minishell: syntax error near unexpected token `newline'\n"

void	is_env_exit_status(char *env_var, char **value, int len_var, 
t_stock *s);
void	word_between_simple_quote(int *i, char *user_input, int *quote);
void	find_env_var(char **tab_env_var, char **envp, char **value, int i);
void	free_get_path_exec_one(char **path, char *exec, char **jobs, char *tmp);
void	free_get_path_exec_two(char **path, char *exec, char **jobs, char *tmp);
void	spend_if_multiple_dollars(char *user_input, int *i);

int		check_pipe(t_stock *stock);
int		check_quote(t_stock *stock);
int		check_end_backslash(t_stock *s);
int		number_env_var(char *user_input);
int		check_double_pipe(char *user_input, t_stock *s);
int		remplace_env_var(char *new, char *value);
int		verif_exec(t_stock *stock);
int		management_check_all_path(t_stock *s, int n);
int		free_env_var_data(char **tab, char **value);
int		command_to_jobs(t_stock *s, char **command);
int		nopipe(char **command);
int		verif_metacharacter(t_stock *s, char **command);
int		is_metacharacter(char c);
int		verif_files(t_stock *s);
int		is_escape(int i, char *user_input);
int		verif_redirection_env_var(t_stock *s);
int		check_redirection_null(t_stock *s);
int		free_alloc(char *exec, char **path, char *jobs);
int		check_exec_after_redirection(t_stock *s, int n, int *status,
char *exec);

int		*ft_intarradd(int *tab, int *size, int n);

char	*env_var(t_stock *s);
char	*remove_and_replace(char *user_input, char **value);
char	*remove_and_replace_utils(char *user_input, char *new, char **value);
char	*ft_itoa(int n);
char	*get_value(char *user_input);

char	**get_path(char **envp);
char	**split_command(char *cmd);
char	**split_cmd(char *user_input);
char	**pre_malloc_arrstring(int nb_env_var);
char	**get_env_var(char *user_input, int nb_env_var);

#endif
