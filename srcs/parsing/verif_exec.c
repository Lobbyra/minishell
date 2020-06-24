/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 13:39:40 by jereligi          #+#    #+#             */
/*   Updated: 2020/06/24 16:16:21 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char      *check_all_path(char **envp, char *command)
// {
//     int             i;
//     char            *exec;
//     char            *tmp;
// 	char			**path;
//     struct stat     buf;

//     i = 0;
//     exec = ft_strjoin("/", command);
// 	path = get_path(envp);
//     while (path[i])
//     {
//         tmp = ft_strjoin(path[i], exec);
//         errno = 0; 
//         stat(tmp, &buf);
//         if (errno == 0)
// 		{
// 			free(exec);
// 			free(path);
// 			return (tmp);
// 		}
// 		free(tmp);
//         i++;
//     }
//     return (ERR_PARSING_PATH);
// }

static int     check_path(t_stock *stock, char *command)
{
    struct stat     buf;

    stat(command, &buf);
    if (errno != 0)
	{
		ft_strjoin(stock->error_strings, \
		ft_strjoin("minishell: no such file or directory: ", command));
		return (1);
	}
    return (0);
}

static int		check_is_slash(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i]  == '/')
			return (1);
		else if (str[i] == '/')
			return (2);
		i++;
	}
	return (0);
}

int				verif_exec(t_stock *s, char **command)
{
	int i;
	int	n;
	int ret;
	int	status;

	i = 0;
	status = 0;
	while (command[i])
	{
		n = 0;
		while (command[i][n])
		{
			if (command[i][n] == '|')
				status = 1;
			else if (i == 0 || status == 1)
			{
				l_printf("exec:%s\n", &command[i][n]);
				if ((ret = check_is_slash(&command[i][n])) != 0)
				{
					if (ret == 1)
						if (check_path(s, &command[i][n]) == 1)
						{
							
						}
				}
				status = 0;
				break ;
			}
			n++;
		}
		i++;
	}
	return (0);
}