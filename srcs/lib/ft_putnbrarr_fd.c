//
// Created by Jérémy Caudal on 29/04/2020.
//

#include "minishell.h"

void	ft_putnbrarr_fd(int *tab, int size, int fd)
{
	int i;

	i = 0;
	if (tab && fd > 0)
	{
		while (i + 1 < size)
		{
			ft_putnbr_fd(tab[i++], fd);
			write(fd, ", ", 2);
		}
		if (i < size)
			ft_putnbr_fd(tab[i], fd);
	}
}
