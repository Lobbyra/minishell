/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 13:22:27 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/07 15:41:20 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_COMMAND_H
# define SPLIT_COMMAND_H

/*
**	int protos
*/
int		is_special_c(char *c);
int		skip_part(char **cmd);
int		part_len(char *str, char first_letter);

/*
**	void protos
*/
void	ft_putarrstr(char **argv, char *sep);

/*
**	char * protos
*/
char	*single_quoted_remover(char *arg);
char	*single_meta_quoted(char *arg, char *cmd);
char	*part_add(char *arg, char *cmd, int p_len);

/*
**	char ** protos
*/
char	**init_split(int n_args);
char	**join_outpend(char **arr);

/*
**	t_bool protos
*/
t_bool	is_single_quoted_meta(char *arg, char *cmd);

#endif
