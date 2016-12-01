#include "fillit.h"

int		main(int ac, char **av)
{
	char		buffer[1024];
	int			nb_p;
	t_piece		*tab;
	int			n_piece;
	int			fd;
	char		**tab_f;
	t_point		cursor;
	int			*e;

	*e = 5;
	cursor.x = 0;
	cursor.y = 0;
	fd = open(av[1], O_RDONLY);
	read(fd, buffer, 1024);
	nb_p = valid_file(buffer);
	if (nb_p == 0)
		return (0);
	tab = save_piece(buffer, nb_p);
	tab_f = test(tab, 4, cursor);
	n_piece = 0;
	while(tab_f[n_piece])
	{
		printf("%s\n", tab_f[n_piece]);
		n_piece++;
	}
	return (0);
}
