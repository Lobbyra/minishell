/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 11:48:04 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/04 11:48:38 by jecaudal         ###   ########.fr       */
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
}				t_stock;

#endif
