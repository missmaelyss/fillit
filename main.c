#include "fillit.h"

int		main(int ac, char **av)
{
	char		buffer[1024];
	int		nb_p;
	t_piece		*tab;
	int 		n;
	int		n2;
	int		fd;
	
	fd = open(av[1], O_RDONLY);
//	printf("%d\n", fd);
	read(fd, buffer, 1024);

//	printf("%s\n", buffer);
	nb_p = valid_file(buffer);
//	printf("%d\n", nb_p);
	if (nb_p == 0)
		return (0);
	tab = save_piece(buffer, nb_p);
/*	n2 = 0;
	while (n2 < nb_p)
	{
		n = 0;
		while (n < 4)
		{
			printf("x = %d, y = %d,		char = %c\n", tab[n2].cd[n].x, tab[n2].cd[n].y, tab[n2].c);
			n++;
		}
		printf("\n");
		n2++;
	}
*/	printf("%d\n", size_piece(tab[0]));
	return (0);
}
