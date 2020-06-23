/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 15:17:09 by jecaudal          #+#    #+#             */
/*   Updated: 2020/06/22 16:36:33 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

static void		pass_word(char **i)
{
	char quote;
	
	while(**i && **i != ' ')
		if (**i == '\'' || **i == '\"')
		{
			quote = **i;
			(*i)++;
			while (**i != quote && *(*i - 1) != '\\' && **i)
			{
				if (**i == '\\' && *(*i + 1) == ' ')
					(*i) += 2;
				(*i)++;
			}
			if (**i == quote)
				(*i)++;
		}
		else
			while (**i && **i != ' ' && 
			!((**i == '\'' || **i == '\"') && *(*i - 1) != '\\'))
			{
				if (**i == '\\' && *(*i + 1) == ' ')
					(*i) += 2;
				(*i)++;
			}
}

int		word_counter(char *user_input)
{
	char	*i;
	int		count;

	count = 0;
	i = user_input;
	while (*i)
	{
		while (*i == ' ')
			i++;
		if (*i)
		{
			count++;
			pass_word(&i);

		}
		if (*i && (*i == ' ' || *i == '\0'))
			i++;
	}
	return (count);
}
/*
int		main(int argc, char **argv)
{
	if (argc == 2)
		printf("in [%s] ", argv[1]);
		fflush(stdout);
		printf("there is %d correct words.\n", word_counter(argv[1]));
		fflush(stdout);
	return (0);
}
*/