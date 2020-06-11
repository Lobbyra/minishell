/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcleaner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Lobbyra <Lobbyra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 14:01:32 by Lobbyra           #+#    #+#             */
/*   Updated: 2020/04/21 15:46:08 by Lobbyra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*
** This function return your string less extra spaces at start and end of the
** string. It will also put only one space to separate words.
** A word is a sequence of non-spaces char value.
*/

static void		copy_word(char **i_str, char **i_new)
{
	while (**i_str != ' ' && **i_str)
	{
		**i_new = **i_str;
		*i_new += 1;
		*i_str += 1;
	}
}

static void		pass_spaces(char **i_str)
{
	while (**i_str == ' ')
		*i_str += 1;
}

static int		how_many_word(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str)
			count++;
		while (*str != ' ' && *str)
			str++;
	}
	return (count);
}

static int		how_many_letter(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		if (*str != ' ')
			count++;
		str++;
	}
	return (count);
}

char			*ft_strcleaner(char *str)
{
	char	*new;
	char	*i_new;
	char	*i_str;
	int		n_word;

	n_word = how_many_word(str);
	if (!(new = (char*)malloc(sizeof(char) *
			(how_many_letter(str) + n_word - 1) + 2)))
		return (NULL);
	i_new = new;
	i_str = str;
	while (*i_str)
	{
		pass_spaces(&i_str);
		copy_word(&i_str, &i_new);
		if (*i_str && n_word > 0)
		{
			*i_new = ' ';
			i_new++;
			n_word--;
		}
	}
	free(str);
	*i_new = '\0';
	return (new);
}
