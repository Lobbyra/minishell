//
// Created by Jérémy Caudal on 01/06/2020.
//

#include "minishell.h"

static int	cast_engine(int fds_input[2], char *path)
{
	int		fd;
	int		ret;
	char	*buf;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (ERR_ERRNO);
	while ((ret = get_next_line(fd, &buf)) != -1 && ret != 0)
	{
		write(fds_input[1], buf, ft_strlen(buf));
		free(buf);
	}
	if (buf)
		free(buf);
	if (ret == -1)
		return (ERR_MALLOC);
	return (0);
}

int			input_caster(int fds_input[2], char *command)
{
	int		err;
	char	*path;

	while (*command)
	{
		while (ft_strncmp(command, " < ", 3) != 0 && *command)
			command++;
		if (*command == '\0')
			break;
		command += 2;
		if (!(path = ft_get_this_word(command)))
			return (ERR_MALLOC);
		if ((err = cast_engine(fds_input, path)) != 0)
		{
			free(path);
			return (err);
		}
		free(path);
	}
	return (0);
}
