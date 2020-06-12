#include <stdio.h>
#include <dirent.h>

// struct dirent {
//     ino_t          d_ino;       /* numéro d'inœud */
//     off_t          d_off;       /* décalage jusqu'à la dirent suivante */
//     unsigned short d_reclen;    /* longueur de cet enregistrement */
//     unsigned char  d_type;      /* type du fichier */
//     char           d_name[256]; /* nom du fichier */
// };

int main (int ac, char **av) 
{
	DIR 			*pDir;
    struct dirent	*pDirent;

    if (ac != 2)
	{
        printf ("Usage: ./a.out <dirname>\n");
            return (1);
    }
    pDir = opendir(av[1]);
    if (pDir == NULL) 
	{
        printf ("Cannot open directory '%s'\n", av[1]);
        return (1);
    }
    while ((pDirent = readdir(pDir)) != NULL)
	{
		// printf("[%c]\t", pDirent->d_type);
        printf("[%s]\n", pDirent->d_name);
	}
    closedir(pDir);
    return (0);
}
