/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:45:38 by jecaudal          #+#    #+#             */
/*   Updated: 2020/07/13 18:23:05 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This function will split the user_input accord to quotes rules and special
**	caracters are separator.
**	Vocab :
**		- char *ui = char *user_input
**		- quote = simple quote '\''
**		- dquote = double quote '\"'
**		- nquote = non quote char
*/

#include "minishell.h"

int		word_counter(char *ui)
{
	int		i;
	int		i_temp;
	int		count;

	i = 0;
	count = 0;
	while (ui[i])
	{
		if (ui[i] == ' ')
			i = pass_spaces(ui, i);
		if (ui[i] && is_sep_char(ui, i) == FALSE)
			count++;
		i_temp = pass_word(ui, i);
		if (i == i_temp && is_sep_char(ui, i) == TRUE && ui[i] != ' ')
		{
			count++;
			if (ft_strncmp(ui + i, ">>", 2) == 0)
				i += 2;
			else
				i++;
		}
		else if (i != i_temp)
			i = i_temp;
	}
	return (count);
}

char	**split_cmd(char *ui)
{
	int		i;
	int		i_temp;
	char	**new;
	char	**i_new;

	if (!(new = (char**)malloc(sizeof(char*) * (word_counter(ui) + 1))))
		return (NULL);
	i_new = new;
	i = 0;
	while (ui[i])
	{
		i = pass_spaces(ui, i);
		i_temp = pass_word(ui, i);
		if (i_temp != i)
		{
			*i_new = ft_strdup_n(ui + i, i_temp - i);
			i = i_temp;
			i_new++;
		}
		else if (ui[i])
		{
			if (ft_strncmp(ui + i, ">>", 2) == 0)
			{
				*i_new = ft_strdup(">>");
				i += 2;
			}
			else
				*i_new = ft_ctostr(ui[i++]);
			i_new++;
		}
	}
	*i_new = NULL;
	return (new);
}

/*
int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		printf("[%s] splitted = \n", argv[1]);
		ft_putarrstr(split_cmd(argv[1]), "], [");
		write(1, "\n", 1);
	}
	return (0);
}
*/
