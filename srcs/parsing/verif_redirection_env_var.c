/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_redirection_env_var.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <jereligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 18:42:30 by jereligi          #+#    #+#             */
/*   Updated: 2020/07/16 18:28:50 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*is_env_var(char *str)
{
	int		i;
	int		n;
	int		x;
	char	*tmp;

	i = 0;
	n = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '$')
	{
		i++;
		while (ft_isalnum(str[i + n]) && str[i + n])
			n++;
	}
	if (!(tmp = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	x = 0;
	while (x < n)
	{
		tmp[x] = str[i];
		i++;
		x++;
	}
	tmp[n] = '\0';
	return (tmp);
}

static int		if_exist(t_stock *s, char *str)
{
	int		len_var;
	int		n;

	n = 0;
	while (s->envp[n])
	{
		len_var = ft_strlen_c(s->envp[n], '=');
		if (ft_strncmp(str, s->envp[n], len_var) == 0)
			return (1);
		n++;
	}
	return (0);
}

char			*remove_incorrect_input(t_stock *s, int i)
{
	int		n;
	char	*tmp;

	n = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(s->user_input) + 1))))
		return (NULL);
	while (n < i)
	{
		tmp[n] = s->user_input[n];
		n++;
	}
	while (s->user_input[i] && s->user_input[i] != '|')
		i = i + 1;
	if (s->user_input[i] == '|')
	{
		while (s->user_input[i] != '\0')
		{
			tmp[n] = s->user_input[i];
			n++;
			i = i + 1;
		}
	}
	tmp[n] = '\0';
	if (s->is_debug == TRUE)
		l_printf("tmp [%s]\n", tmp);
	return (tmp);
}

int				err_redirection_env_var(t_stock *s, char *str, int *i, int jobs)
{
	char *tmp;

	s->list_exec_abort = ft_intarradd(s->list_exec_abort, &s->size_list, jobs);
	s->error_strings = ft_strjoindel(s->error_strings, "minishell: ", 1);
	s->error_strings = ft_strjoindel(s->error_strings, str, 1);
	s->error_strings = ft_strjoindel(s->error_strings, \
	": ambiguous redirect\n", 1);
	tmp = remove_incorrect_input(s, *i);
	free(s->user_input);
	s->user_input = tmp;
	*i = *i - 1;
	return (0);
}

int				verif_redirection_env_var(t_stock *s)
{
	int		i;
	int		jobs;
	char	*tmp;

	i = 0;
	jobs = 0;
	s->size_list = 0;
	while (s->user_input[i])
	{
		if (s->user_input[i] == '|')
			jobs++;
		else if (is_metacharacter(s->user_input[i]))
		{
			tmp = is_env_var(&s->user_input[i + 1]);
			if (tmp[0] != '\0')
				if ((if_exist(s, tmp)) == 0)
					err_redirection_env_var(s, tmp, &i, jobs);
			free(tmp);
		}
		i++;
	}
	return (0);
}
