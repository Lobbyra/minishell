//
// Created by Jérémy Caudal on 23/04/2020.
//

/*
 * This part is for command execution.
 */

#include "minishell.h"

/*
static int	process_exec(t_stock *s, t_exec *exec)
{
	int pid;
	int status;

	if ((pid = fork()) == 0)
	{
		//child
	}
	if (pid == -1)
		return (ERR_ERRNO);
	if (pid != 0)
	{
		signal(SIGINT, SIG_IGN);
		while (waitpid(pid, &status, WNOHANG))
		{
			if (exec->is_fileout_redir || exec->is_pipe)
			{

			}
		}
	}
}
*/

int 		execution(t_stock *s)
{
	int error;
	t_exec	*exec;

	if ((error = init_t_exec(s, &exec)) != 0)
		return (error);
	s->prev_cmd_is_piped = exec->is_pipe;
	// WIP error = process_exec(s, exec);
	if (fork() == 0)
		cast_redir(s, exec);
	if (s->is_debug_mode == TRUE)
		print_t_exec(exec);
	free_t_exec(exec, s);
	if (error != 0)
		return (error);
	return (0);
}
