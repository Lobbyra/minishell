//
// Created by Jérémy Caudal on 27/04/2020.
//

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	char *t_s1;

	t_s1 = s1;
	while (*t_s1 == *s2 && *t_s1 != '\0' && *s2 != '\0' && t_s1 - s1 + 1 < n)
	{
		t_s1++;
		s2++;
	}
	return (*t_s1 - *s2);
}
