/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 14:39:55 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/13 16:54:36 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_CMD_H
# define SPLIT_CMD_H

/*
**	INT
*/
int		pass_word(char *ui, int i);
int		pass_quote(char *ui, int i);
int		pass_dquote(char *ui, int i);
int		pass_spaces(char *ui, int i);

/*
**	T_BOOL
*/
t_bool	is_escaped(char *cmd, int i);
t_bool	is_sep_char(char *cmd, int i);

#endif
