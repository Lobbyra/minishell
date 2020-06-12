int main()
{
	char *coucou;

	coucou = strdup("Je m'appelle jeremy !");
	if (fork() == 0)
	{
		coucou = strdup("Je m'appelle pierre !");
		exit(0);
	}
	printf("coucou = %s", coucou);
	return (0);
}
