/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 11:48:04 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/16 16:00:55 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef char	t_bool;

typedef struct	s_stock
{
	char		**envp;
	char		*user_input;
	char		*buf_user_input;
	char		***jobs;
	int			n_jobs;
	t_bool		is_pipe;
	int			*pipes;
	char		exit_status;
	char		*error_strings;
	t_bool		is_debug;
	t_bool		is_cmd_closed;
	t_bool		is_exec_abort;
	int			*list_exec_abort;
	int			size_list;
}				t_stock;

#endif
