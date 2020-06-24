/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 16:29:39 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/24 17:06:22 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define ERR_QUOTE1 "minishell: unexpected EOF while looking for matching `"
# define ERR_QUOTE2 "\'\nminishell: syntax error: unexpected end of file"
# define ERR_PIPE "minishell: syntax error: unexpected end of file"

int		check_quote(t_stock *stock);
int	 	check_pipe(t_stock *stock);
int		check_end_backslash(t_stock *s);
char	*env_var(t_stock *s);
char	**pre_malloc_arrstring(int nb_env_var);
int		number_env_var(char *user_input);
int		free_env_var_data(char **tab, char **value);
char	*remove_and_replace(char *user_input, char **tab, char **value);
int		remplace_env_var(char *new, char *value);
int		check_double_pipe(char *user_input);
int		verif_exec(t_stock *stock, char **command);
char    **get_path(char **envp);
int		command_to_jobs(t_stock *s, char **command);

#endif