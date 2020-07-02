/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 16:29:39 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/02 14:48:30 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define ERR_QUOTE1 "minishell: unexpected EOF while looking for matching `"
# define ERR_QUOTE2 "\'\nminishell: syntax error: unexpected end of file\n"
# define ERR_PIPE "minishell: syntax error: unexpected end of file\n"

int	 	check_pipe(t_stock *stock);
int		check_quote(t_stock *stock);
int		check_end_backslash(t_stock *s);
int		number_env_var(char *user_input);
int		check_double_pipe(char *user_input);
int		remplace_env_var(char *new, char *value);
int		verif_exec(t_stock *stock);
int		management_check_all_path(t_stock *s, int n, t_bool is_debug);
int		free_env_var_data(char **tab, char **value);
int		command_to_jobs(t_stock *s, char **command);
int		nopipe(char **command);
int		verif_metacharacter(t_stock *s, char **command);
int		is_metacharacter(char c);
int		verif_files(t_stock *s);


char	*env_var(t_stock *s);
char	*remove_and_replace(char *user_input, char **tab, char **value);

char    **get_path(char **envp);
char	**split_command(char *cmd);
char	**pre_malloc_arrstring(int nb_env_var);

#endif