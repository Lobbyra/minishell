//
// Created by Jérémy Caudal on 27/04/2020.
//

#include "minishell.h"

static int 		panic_init_exec(t_exec *exec, t_stock *s, int err)
{
	free_t_exec(exec, s);
	printf("PANIC INIT EXEC code = %d\n", err);
	fflush(stdout);
	return (err);
}

static char 	*cut_bin_path(char *command)
{
	char 	*new;
	char	*temp;
	int		path_len;

	temp = command;
	path_len = 0;
	while (*temp && *temp != ' ')
	{
		path_len++;
		temp++;
	}
	if (!(new = (char*)malloc(sizeof(char) * (path_len + 1))))
		return (NULL);
	temp = new;
	while (path_len)
	{
		*temp = *command;
		temp++;
		command++;
		path_len--;
	}
	*temp = '\0';
	return (new);
}

static char		**arg_setup(char *command, char *bin_path)
{
	char **new;

	if (!(new = ft_split(command, " ")))
		return (NULL);
	free(new[0]);
	if (!(new[0] = ft_basename(bin_path)))
	{
		ft_freestrs(new + sizeof(char**));
		return (NULL);
	}
	return (new);
}

int				init_t_exec_p2(t_stock *stock, t_exec *n)
{
	int error;

	n->is_fileout_redir = is_files_in_output(stock->command);
	n->is_filein_redir = is_files_in_input(stock->command);
	n->is_pipe = is_pipe(stock->user_input);
	if (stock->fds_pipe[0] == 0 && stock->fds_pipe[1] == 0)
		n->is_piped = FALSE;
	else
		n->is_piped = TRUE;
	if (n->is_pipe == TRUE && pipe(stock->fds_pipe) == -1)
			return (ERR_ERRNO);
	return (0);
}

int 			init_t_exec(t_stock *stock, t_exec **exec)
{
	t_exec	*n;
	int		error;

	if (!(n = (t_exec*)malloc(sizeof(t_exec))))
		return (ERR_MALLOC);
	n->n_output_files = count_out_files(stock->command);
	if (!(n->fds_output_files = file_opener(stock->command, n->n_output_files)))
		panic_init_exec(n, stock, ERR_MALLOC);
	if (!(n->path_bin = cut_bin_path(stock->command)))
		panic_init_exec(n, stock, ERR_MALLOC);
	if (!(n->argv = arg_setup(stock->command, n->path_bin)))
		panic_init_exec(n, stock, ERR_MALLOC);
	if (!(n->argv = redirection_rm(n->argv)))
		panic_init_exec(n, stock, ERR_MALLOC);
	if ((error = init_t_exec_p2(stock, n) != 0))
		panic_init_exec(n, stock, error);
	if ((error = pipe(n->fds_c2p)) == -1)
		return (error);
	*exec = n;
	return (0);
}
