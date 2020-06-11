#include "minishell.h"

static int	start_copy_position(char *path)
{
	int i;

	i = ft_strlen(path) - 1;
	while (i > 0 && path[i] == '/')
		i--;
	return (i);
}

static int	basename_len(char *path, int i)
{
	int count;

	count = 0;
	while (i > 0 && path[i] == '/')
		i--;
	while (i >= 0 && path[i] != '/')
	{
		i--;
		count++;
	}
	if (count == 0)
		return (1);
	return (count);
}

char		*ft_basename(char *path)
{
	int		i;
	char	*new;
	int		ret_len;

	i = start_copy_position(path);
	if (i == -1)
		return (ft_strdup(""));
	ret_len = basename_len(path, i);
	if (!(new = (char*)malloc(sizeof(char) * (ret_len + 1))))
		return (NULL);
	new[ret_len--] = '\0';
	while (ret_len >= 0)
	{
		new[ret_len] = path[i];
		i--;
		ret_len--;
	}
	return (new);
}
