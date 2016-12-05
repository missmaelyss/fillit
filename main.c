#include "fillit.h"

int		main(int ac, char **av)
{
	char		buffer[1024];
	int			nb_p;
	t_piece		*tab;
	int			fd;
	char		**tab_f;

	fd = open(av[1], O_RDONLY);
	read(fd, buffer, 1024);
	nb_p = valid_file(buffer);
	if (nb_p == 0)
		return (0);
	tab = save_piece(buffer, nb_p);
	tab_f = write_tab(tab, nb_p);
	nb_p = 0;
/*	while(tab_f[nb_p])
	{
		printf("%s\n", tab_f[nb_p]);
		nb_p++;
	}*/
	return (0);
}

