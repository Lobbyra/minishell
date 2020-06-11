//
// Created by Jérémy Caudal on 30/04/2020.
//

#include "minishell.h"

static int		ft_is_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (c != charset[i] && charset[i])
		i++;
	if (charset[i])
		return (0);
	return (1);
}

static int		ft_lw(char *str, int i, char *charset)
{
	int j;

	j = 0;
	while (ft_is_charset(str[i], charset) && str[i])
	{
		i++;
		j++;
	}
	return (j);
}

static int		ft_count_word(char *str, char *charset)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i] && charset[0])
	{
		while (ft_is_charset(str[i], charset) == 0)
			i++;
		if (str[i])
			nb++;
		while (ft_is_charset(str[i], charset) == 1 && str[i])
			i++;
	}
	if (!(charset[0]))
		return (1);
	return (nb);
}

char			**ft_split(char *str, char *charset)
{
	int		i_str;
	int		i_word;
	int		i_letter;
	char	**argv;

	i_str = 0;
	i_word = 0;
	if (!str || !charset
		|| !(argv = malloc(sizeof(char*) * (ft_count_word(str, charset) + 1))))
		return (NULL);
	while (i_word < ft_count_word(str, charset) && str[0])
	{
		i_letter = 0;
		while (ft_is_charset(str[i_str], charset) == 0 && str[i_str])
			i_str++;
		argv[i_word] = malloc(sizeof(char) * ft_lw(str, i_str, charset) + 1);
		if (!(argv[i_word]))
			return (NULL);
		while (ft_is_charset(str[i_str], charset) == 1 && str[i_str])
			argv[i_word][i_letter++] = str[i_str++];
		argv[i_word][i_letter] = '\0';
		i_word++;
	}
	argv[i_word] = NULL;
	return (argv);
}