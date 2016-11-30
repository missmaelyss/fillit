#include "fillit.h"

int		main(int ac, char **av)
{
	char		buffer[1024];
	int		nb_p;
	t_piece		*tab;
	int 		n_point;
	int		n_piece;
	int		fd;
	int		n_carre;
	int		n_tmp;
	char	prout;

	fd = open(av[1], O_RDONLY);
	printf("Infos\n-----\n> fd = %d\n", fd);
	read(fd, buffer, 1024);

	nb_p = valid_file(buffer);
	printf("> Il y a %d piece", nb_p);
	if (nb_p > 1)
		printf("s");
	printf("\n");
	if (nb_p == 0)
		return (0);
	tab = save_piece(buffer, nb_p);
	n_piece = 0;
	while (n_piece < nb_p)
	{
		n_point = 0;
		printf("\npiece n*%d\nAvant\n------", n_piece + 1);
		while (n_point < 4)
		{
			n_carre = 0;
			printf("\nx = %d, y = %d,		char = %c		", tab[n_piece].cd[n_point].x, tab[n_piece].cd[n_point].y, tab[n_piece].c);
			while (n_carre < 4)
			{
				n_tmp = 0;
				prout = '0';
				while (n_tmp < 4)
				{
					if (n_carre + 1 == tab[n_piece].cd[n_tmp].x && n_point + 1 == tab[n_piece].cd[n_tmp].y)
						prout = tab[n_piece].c;
					n_tmp++;
				}
				if (prout != '0')
					printf("%c", prout);
				else
					printf(".");
				n_carre++;
			}
			n_point++;
		}
		printf("\nApres\n------");
		tab[n_piece] = move_up_left(tab[n_piece]);
		n_point = 0;
		while (n_point < 4)
		{
			n_carre = 0;
			printf("\nx = %d, y = %d,		char = %c		", tab[n_piece].cd[n_point].x, tab[n_piece].cd[n_point].y, tab[n_piece].c);	
			while (n_carre < 4)
			{
				n_tmp = 0;
				prout = '0';
				while (n_tmp < 4)
				{
					if (n_carre + 1 == tab[n_piece].cd[n_tmp].x && n_point + 1 == tab[n_piece].cd[n_tmp].y)
						prout = tab[n_piece].c;
					n_tmp++;
				}
				if (prout != '0')
					printf("%c", prout);
				else
					printf(".");
				n_carre++;
			}
			n_point++;
		}
		printf("\n> Le cote du carre le plus petit pouvant contenir la piece est %d\n\n", size_piece(tab[n_piece]));
		n_piece++;
	}
	return (0);
}
