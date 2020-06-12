//
// Created by Jérémy Caudal on 29/04/2020.
//

#include "minishell.h"

static void part2(t_exec *exec)
{
	ft_putstr("is_fileout_redir = ");
	if (exec->is_fileout_redir == TRUE)
		ft_putstr("TRUE");
	else
		ft_putstr("FALSE");
	ft_putstr("\n");
	ft_putstr("is_filein_redir = ");
	if (exec->is_filein_redir == TRUE)
		ft_putstr("TRUE");
	else
		ft_putstr("FALSE");
	ft_putstr("\n");
	ft_putstr("is_pipe = ");
	if (exec->is_pipe == TRUE)
		ft_putstr("TRUE");
	else
		ft_putstr("FALSE");
	ft_putstr("\n");
	ft_putstr("is_piped = ");
	if (exec->is_piped == TRUE)
		ft_putstr("TRUE");
	else
		ft_putstr("FALSE");
	ft_putstr("\n");
	ft_putstr("\n\n");
}

void 		print_t_exec(t_exec *exec)
{
	ft_putstr("T_EXEC DEBUG\n");
	ft_putstr("n_output_files = ");
	ft_putnbr_fd(exec->n_output_files, 1);
	ft_putstr("\n");
	ft_putstr("fds_output_files = ");
	if (exec->fds_output_files)
		ft_putnbrarr_fd(exec->fds_output_files, exec->n_output_files, 1);
	else
		ft_putstr("(null)");
	ft_putstr("\n");
	ft_putstr("argv = ");
	if (exec->argv)
		ft_putarrstr_fd(exec->argv, ",", 1);
	else
		ft_putstr("(null)");
	ft_putstr("\n");
	ft_putstr("path_bin = ");
	if (exec->path_bin)
		ft_putstr(exec->path_bin);
	else
		ft_putstr("(null)");
	ft_putstr("\n");
	part2(exec);
}
