/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 14:38:32 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/23 15:57:41 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

/*
** Prend la une partie d'un argument et la mesure en fonction de son premier
** char.
** Si str[0] != '\'' && str[0] != '\"' :
**		S'arrete de compter au premier quote ou espace (non escape)
**		qu'il rencontre.
** Si str[0] == '\"' || str[0] == '\'' :
**		S'arrete de compter a la prochaine iteration (non escape) de str[0];
*/

static int	part_len_dquote(char *str)
{
	int count;

	str++;
	count = 0;
	while (*str)
	{
		if (*str == '\"' && *(str - 1) != '\\')
			break;
		if (*str == '\\' &&
		(*(str + 1) == '\"' || *(str + 1) == '$' || *(str + 1) == '`'))
			str++;
		str++;
		count++;
	}
	return (count);
}

static int	part_len_quote(char *str)
{
	int count;
	
	str++;
	count = 0;
	while (*str)
	{
		if (*str == '\'')
			break;
		str++;
		count++;
	}
	return (count);
}

int	part_len(char *str, char first_letter)
{
	int count;

	count = 0;
	if (first_letter == '\"')
		return (part_len_dquote(str));
	else if (first_letter == '\'')
		return (part_len_quote(str));
	else
	{
		while (*str)
		{
			if ((*str == ' ' || *str == '\'' || *str == '\"') &&
				*(str - 1) != '\'')
				break ;
			if (*str == '\\')
				str++;
			count++;
			if (*str)
				str++;
		}
	}
	return (count);
}

/*
int main(int argc, char **argv)
{
	if (argc == 2)
		printf("The len of [%s] is %d\n", argv[1], part_len(argv[1], argv[1][0]));
	return (0);
}
*/