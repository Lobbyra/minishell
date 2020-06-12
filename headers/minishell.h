/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 09:24:35 by jecaudal          #+#    #+#             */
/*   Updated: 2020/04/21 10:22:16 by Lobbyra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** GLOBAL DEFINES
*/

# define TRUE 1
# define FALSE 0
# define ERROR -1
# define STDERR 2
# define STDOUT 1
# define STDIN 0

/*
** INCLUDES
*/

# include "get_next_line.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <libgen.h>
# include <string.h>
# include <sys/wait.h>

/*
** TYPEDEF
*/
typedef char t_bool;

typedef struct	s_stock
{
	char		**envp;
	t_bool		ill_exit;
	char		*user_input;
	char		*command;
	int			storage_return;
	t_bool		prev_cmd_is_piped;
	int 		fds_pipe[2]; //This variable is modified in exec part.
	t_bool		is_debug_mode;
}				t_stock;

/*
** ERROR SIGNAL VALUE (see parsing.h to see parsing sig value)
*/

# define ERR_MALLOC -2
# define ERR_ERRNO -10


/*
** ERROR MESSAGE STRING (see parsing.h to see parsing message stings)
*/

# define MSG_ERR_MALLOC "Minishell Error : A memory allocation failed.\n"

/*
** GLOBAL PROTOTYPES
*/

int		minishell(t_stock *stock);
int 	execution(t_stock *stock);
int 	parsing(char **command, int storage_return, char **envp);

/*
** LIB PROTOTYPES (srcs/lib/)
*/

t_bool	ft_c_finder(char c, char *set);

int		ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strdupdel(char *str);
char	*ft_basename(char *path);
char	*ft_strcleaner(char *str);
int		ft_strlen_n(char *str, int n);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup_n(char *str, int n);
char	**ft_split(char *str, char *charset);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
void	*ft_memcpy_n(void *s1, void *s2, unsigned int n);

void	ft_freestrs(char **strs);
int		ft_strarrlen(char **arr);
void	ft_strarrfree(char **arr);
char	**ft_strarrdup(char **arr);
void	ft_putstrarr_fd(char **argv, char *sep, int fd);
char	**ft_strarrnuller(char **tab, unsigned int size);

void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	print_t_stock(t_stock *s);
void	ft_putnbr_fd(int nb, int fd);
void	print_err_parsing(int error);
void	ft_putchar_fd(char c, int fd);
void	print_err_execution(int error);
void	ft_putnbrarr_fd(int *tab, int size, int fd);
void	ft_putarrstr_fd(char **arr, char *sep, int fd);

/*
 *  SUB PRE-PROC FILES
 */

# include "execution.h"
# include "parsing.h"

/*
 * SUB SRC CODES
 */


#endif
