/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_outpend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:48:15 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/04 10:38:10 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	This function will return arr with all two strings ">" followed replaced
**	by ">>".
*/

static int	panic(char **new, char **i_new)
{
	while (i_new >= new)
	{
		free(*i_new);
		i_new--;
	}
	free(new);
	return (ERR_MALLOC);
}

static int	copy_the_rest(char **new, char **i_new, char **arr)
{
	while (*arr)
	{
		if ((*i_new = ft_strdup(*arr)) == NULL)
			return (panic(new, i_new));
		arr++;
		i_new++;
	}
	return (0);
}

static char	**panic_replacement(char **new, char **i_new)
{
	while (i_new >= new)
	{
		free(*i_new);
		i_new--;
	}
	free(new);
	return (NULL);
}

static char	**replacement(char **arr)
{
	char	**new;
	char	**i_new;

	if (!(new = (char**)malloc(sizeof(char*) * (ft_strarrlen(arr)))))
		return (NULL);
	i_new = new;
	*(new + ft_strarrlen(arr) - 1) = NULL;
	while (*arr)
	{
		if (ft_strcmp(*arr, ">") == 0 && ft_strcmp(*(arr + 1), ">") == 0)
		{
			if ((*i_new = ft_strdup(">>")) == NULL)
				return (panic_replacement(new, i_new));
			arr += 2;
			i_new++;
			if (copy_the_rest(new, i_new, arr) != 0)
				return (NULL);
			break ;
		}
		else if ((*i_new = ft_strdup(*arr)) == NULL)
			return (panic_replacement(new, i_new));
		arr++;
		i_new++;
	}
	return (new);
}

char		**join_outpend(char **arr)
{
	char	**temp;
	char	**i_arr;

	i_arr = arr;
	while (*i_arr)
	{
		if (ft_strcmp(*i_arr, ">") == 0 && ft_strcmp(*(i_arr + 1), ">") == 0)
		{
			temp = replacement(arr);
			ft_freestrs(arr);
			arr = temp;
			i_arr = arr;
		}
		i_arr++;
	}
	return (arr);
}
