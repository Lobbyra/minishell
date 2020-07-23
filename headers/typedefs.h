/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 11:48:04 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/23 18:12:21 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef char	t_bool;

typedef struct		s_stock
{
	char			**envp;
	char			*user_input;
	char			*buf_user_input;
	char			***jobs;
	int				n_jobs;
	t_bool			is_pipe;
	int				*pipes;
	int				exit_status;
	char			*error_strings;
	t_bool			is_debug;
	t_bool			is_cmd_closed;
	t_bool			is_exec_abort;
	int				*list_exec_abort;
	int				size_list;
}					t_stock;

typedef struct		s_child
{
	char			**job;
	char			*path;
	char			**args;
	int				jobpos;
	char			*exec_name;
	pid_t			pid;
	int				*pipes;
	t_bool			is_pipe;
	t_bool			is_aborted;
	t_stock			*s;
}					t_child;

#endif
