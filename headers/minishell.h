/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:22:38 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/08 18:08:12 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define TRUE 1
# define FALSE 0
# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define SIG_CTRLD 1

# define ERR_MALLOC 1
# define ERR_ERRNO 2
# define ERR_SYNTAX 3
# define ERR_EXIT 4
# define ERR_CMD_VOID 5

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <libgen.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "get_next_line.h"

# include "typedefs.h"
# include "lib.h"
# include "parsing.h"
# include "execution.h"
# include "error_messages.h"
# include "split_command.h"

void			print_prompt(void);
void			reset(t_stock *stock);
void			error_printer(int err);
int				parsing(t_stock *stock);
char			**find_exec(char **job);
t_stock			*init_stock(char **envp);
int				execution(t_stock *stock);
int				wait_instruction(t_stock *s);
void			free_t_stock(t_stock *stock);

/*
**	Sub functions of wait_instruction
*/
int				check_user_input(char *user_input);
int				panic_wait_instruction(char **to_free, int err);

/*
**	Debug functions.
*/
void			print_jobs(char ***jobs, int n_jobs);

#endif
