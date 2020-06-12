//
// Created by Jérémy Caudal on 29/04/2020.
//

#include "minishell.h"

void free_t_exec(t_exec *exec, t_stock *stock)
{
	if (exec)
	{
		ft_close_fds(exec->fds_output_files, exec->n_output_files);
		if (exec->fds_output_files)
			free(exec->fds_output_files);
		if (exec->argv)
			ft_freestrs(exec->argv);
		if (exec->path_bin)
			free(exec->path_bin);
		close(exec->fds_c2p[0]);
		close(exec->fds_c2p[1]);
		if (exec->is_pipe == FALSE)
		{
			stock->fds_pipe[0] = 0;
			stock->fds_pipe[1] = 0;
		}
		free(exec);
	}
}
