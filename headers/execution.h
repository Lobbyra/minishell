/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:49:26 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/09 15:56:50 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

/*
** INCLUDES
*/

#include "minishell.h"

/*
** #### TYPEDEF & STRUCT ###
*/

typedef struct	s_exec
{
	int 		n_output_files;
	int 		*fds_output_files;
	char		**argv;
	char		*path_bin;
	t_bool		is_fileout_redir;
	t_bool		is_filein_redir;
	t_bool		is_pipe; // Is our command piped
	t_bool		is_piped; // Is our curr command preced by pipe
	int 		fds_c2p[2];
}				t_exec;

/*
** PROTOTYPES
*/

char	*ft_get_this_word(char *str);
int 	init_t_exec(t_stock *stock, t_exec **exec);
t_bool	is_files_in_output(char *command);
t_bool	is_files_in_input(char *command);
t_bool	is_pipe(char *user_input);
int		count_out_files(char *str);
void 	free_t_exec(t_exec *exec, t_stock *s);
void	print_t_exec(t_exec *exec);
char 	**redirection_rm(char **argv);
int		*file_opener(char *command, int n_out_files);
void	ft_close_fds(int *fds, int n);
int		input_caster(int fds_input[2], char *command);
int		cast_redir(t_stock *s, t_exec *e);
int		ft_fdcaster(int fd_src, int fd_dst);





#endif
