//
// Created by Jérémy Caudal on 19/05/2020.
//

#include <unistd.h>

void	ft_close_fds(int *fds, int n)
{
	n--;
	if (fds)
	{
		while (n >= 0) {
			close(fds[n]);
			n--;
		}
	}
}
